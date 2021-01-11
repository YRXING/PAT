#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

//const int M = 26*26*26*10+1;
const int K = 2510;
vector<string> courslist[K];
int hash_Fuc(string name){
    int id=0;
    for(int i=0;i<3;i++){
        id = id*26+name[i]-'A';
    }
    return id*10+name[3]-'0';
}

int main(){
    int n,k;
    string name;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        cin>>name;
        int cnum;
        scanf("%d",&cnum);
        for(int j=0;j<cnum;j++){
            int cousenum;
            scanf("%d",&cousenum);
            courslist[cousenum].push_back(name);
        }
    }
    for(int i=1;i<=k;i++){
        printf("%d %d\n",i,courslist[i].size());
        sort(courslist[i].begin(),courslist[i].end());
        for(int j=0;j<courslist[i].size();j++)
            printf("%s\n",courslist[i][j].c_str());
    }
    return 0;
}

/*
1.���ݷ�Χ��������һ����char������������ݣ���string �����׳�ʱ
2.�������ֱ�Ӷ��ַ������򣬻ᵼ�´������ַ����ƶ����ǳ�����ʱ�䡣ʹ���ַ����±�����
course[id].push_back(i);
bool cmp(int a,int b){
    return strcmp(name[a],name[b])<0;
}
printf(name[cours[i][j]]);
*/
