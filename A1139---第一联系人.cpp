#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int N=10000;
map<int,bool> arr;//��ϵ����,��int�ᳬʱ
vector<int> v[N];//�����˵�ͬ������
struct node{//����浽������������
    int a,b;
    node(int _a,int _b):a(_a),b(_b){}
};
vector<node> ans;
bool cmp(node x,node y){
    if(x.a!=y.a) return x.a<y.a;
    else return y.b>x.b;
}

int main(){
    int n,m,k;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        if(a.length()==b.length()){//�洢ͬ������
            v[abs(atoi(a.c_str()))].push_back(abs(atoi(b.c_str())));
            v[abs(atoi(b.c_str()))].push_back(abs(atoi(a.c_str())));
        }
        arr[abs(atoi(a.c_str())) * 10000 + abs(atoi(b.c_str()))] = arr[abs(atoi(b.c_str())) * 10000 + abs(atoi(a.c_str()))] = true;
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int c,d;
        cin>>c>>d;
        ans.clear();
        for(int j=0;j<v[abs(c)].size();j++)//�о�c,d��ͬ�����ѣ��ж�ÿһ���Ƿ�������
        for(int k=0;k<v[abs(d)].size();k++){
            if(v[abs(c)][j]==abs(d)||abs(c)==v[abs(d)][k]) continue;
            if(arr[v[abs(c)][j]*10000+v[abs(d)][k]]==true)
                ans.push_back(node(v[abs(c)][j],v[abs(d)][k]));
        }
        sort(ans.begin(),ans.end(),cmp);
        printf("%d\n",ans.size());
        for(int j=0;j<ans.size();j++)
            printf("%04d %04d\n",ans[j].a,ans[j].b);
    }

    return 0;
}

/*
1.������arr����������Ƿ������ѣ��ڽӾ��󣩣���v��������˵�ͬ�����ѣ��ڽӱ�
2.����A,B�����ҵ�A������ͬ������C�����ҵ�B������ͬ������D��C,D�����������
3.A,B��ͬ�����Ѳ�����A��B
4.�����int����һ�����ѣ�-0000��0000��˵����0���޷���֪����˵��Ա�����Ҫ���ַ���
5.�������
*/
