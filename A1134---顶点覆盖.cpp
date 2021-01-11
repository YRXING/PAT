#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    int n,m,k,nv,a,b,num;
    scanf("%d%d",&n,&m);
    vector<int> v[n];
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&nv);
        int flag=0;
        vector<int> Hash(m,0);//0--m-1号边都没有存在过,初始化为0;
        for(int j=0;j<nv;j++){
            scanf("%d",&num);
            for(int t=0;t<v[num].size();t++)
                Hash[v[num][t]]=1;
        }
        for(int j=0;j<m;j++){
            if(Hash[j]==0){
                printf("No\n");
                flag=1;
                break;
            }
        }
        if(flag==0)  printf("Yes\n");
    }
    return 0;
}

/*
用vector v[n]保存某结点属于的某条边的编号，比如a b两个结点构成的这条边的编号为0，
则v[a].push_back(0)，v[b].push_back(0)——表示a属于0号边，b也属于0号边。
对于每一个集合做判断，遍历集合中的每一个元素，
将当前元素能够属于的边的编号i对应的hash[i]标记为1，
表示这条边是满足有一个结点出自集合S中的。
最后判断hash数组中的每一个值是否都是1，如果有不是1的，
说明这条边的两端结点没有一个出自集合S中，则输出No。否则输出Yes～
*/

