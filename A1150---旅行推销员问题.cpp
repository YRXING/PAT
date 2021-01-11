#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

const int maxn=210;
int G[maxn][maxn];
int cnt,sdist=1000000,n,m;

void check(int index)
{
   int t;
   scanf("%d",&t);
   set<int>s;
   vector<int>v(t);
   for(int i=0;i<t;i++)
   {
       scanf("%d",&v[i]);
       s.insert(v[i]);
   }
   bool flag=true;
   int sum=0;
   for(int i=0;i<t-1;i++)
   {
       if(G[v[i]][v[i+1]]==0)
       {
           flag=false;
       }
       sum+=G[v[i]][v[i+1]];
   }

   if(flag==false)
    printf("Path %d: NA (Not a TS cycle)\n",index);
   else if(v[0]!=v[t-1]||s.size()!=n)
    printf("Path %d: %d (Not a TS cycle)\n",index,sum);
   else{
        if(t==n+1)
            printf("Path %d: %d (TS simple cycle)\n",index,sum);
        else
        printf("Path %d: %d (TS cycle)\n",index,sum);
        if(sum<sdist){
            sdist=sum;
            cnt=index;
        }
   }
}

int main(){
    fill(G[0],G[0]+maxn*maxn,0);

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,dist;
        scanf("%d%d%d",&u,&v,&dist);
        G[u][v]=G[v][u]=dist;
    }

    int k,num;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        check(i);
    }
    printf("Shortest Dist(%d) = %d",cnt,sdist);
    return 0;
}
/*
1.如果有相连的路不连通（NA）
2.如果首尾不同||没有经过每一个点(not a ts crcle)
3.1.2满足但遍历数的个数！=n+1，不是简单环(ts cycle)
4.是简单环(ts simple cycle)
使用set容器存经过城市的数量
*/
