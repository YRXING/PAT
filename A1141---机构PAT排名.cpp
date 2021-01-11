#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
    string school;
    int tws, ns;
};
bool cmp(node a, node b) {
    if (a.tws != b.tws)
        return a.tws > b.tws;
    else if (a.ns != b.ns)
        return a.ns < b.ns;
    else
        return a.school < b.school;
}
int main() {
    int n;
    scanf("%d", &n);
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;
    for (int i = 0; i < n; i++) {
        string id, school;
        cin >> id;
        double score;
        scanf("%lf", &score);
        cin >> school;
        transform(school.begin(),school.end(),school.begin(),::tolower);
        if (id[0] == 'B')
            score = score / 1.5;
        else if (id[0] == 'T')
            score = score * 1.5;
        sum[school] += score;
        cnt[school]++;
    }
    vector<node> ans;//������map����Ķ�������ɽ�����vector��������
    for (auto it = cnt.begin(); it != cnt.end(); it++)
        ans.push_back(node{it->first, (int)sum[it->first], cnt[it->first]});

    sort(ans.begin(), ans.end(), cmp);
    int rank = 0, pres = -1;
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (pres != ans[i].tws) rank = i + 1;
        pres = ans[i].tws;
        printf("%d ", rank);
        cout << ans[i].school;
        printf(" %d %d\n", ans[i].tws, ans[i].ns);
    }
    return 0;
}

/*
1.����map��һ��cnt�����洢ĳѧУ���ƶ�Ӧ�Ĳ���������
��һ��sum����ĳѧУ���ƶ�Ӧ���ܼ�Ȩ�ɼ�
2.��Ȩ����ȡ����������Ҫ�������ܺ�ȡ�������֣�����ÿ�ζ�ֱ����int�洢����Ȼ����һ��3�ֲ��Ե㲻ͨ����
PS��֮ǰֱ��ʹ��map���������µ�PATϵͳ���ύ�����һ�����Ե㳬ʱ���ĳ���unordered_map����AC
3.
