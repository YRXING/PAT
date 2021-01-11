#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;
const int N=210;
int G[N][N];
int mp[N];

int main(){
    int n,m;
    memset(G,0,sizeof(G));

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u][v]=G[v][u]=1;
    }
    int k,num;
    scanf("%d",&k);
    vector<int> cash;

    for(int i=0;i<k;i++){
        scanf("%d",&num);
        cash.clear();
        for(int j=0;j<num;j++){
            int v;
            scanf("%d",&v);
            cash.push_back(v);
        }

        if(num!=n+1){
            printf("NO\n");
        }
        else{
            memset(mp,0,sizeof(mp));
            int v,pre,flag=0;
            pre=cash[0];
            for(int j=1;j<num;j++){
                v=cash[j];
                mp[v]++;
                if(!G[pre][v]||mp[v]>1){
                    printf("NO\n");
                    flag=1;
                    break;
                }
                pre=v;
            }
            if(!flag) printf("YES\n");
        }
    }
    return 0;
}
