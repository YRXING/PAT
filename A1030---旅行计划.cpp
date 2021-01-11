#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=510;
const int INF=1000000000;
int G[maxn][maxn],pre[maxn],cost[maxn][maxn],c[maxn],d[maxn];
bool vis[maxn]={false};
int n,m,s,de;

void Dijkstra(int s){
    d[s]=0;
    c[s]=0;
    for(int i=0;i<n;i++) pre[i]=i;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    pre[v]=u;
                    c[v]=c[u]+cost[u][v];
                }else if(d[u]+G[u][v]==d[v]&&c[u]+cost[u][v]<c[v]){
                    c[v]=c[u]+cost[u][v];
                    pre[v]=u;
                }
            }
        }
    }
}

void DFS(int s,int v){
    if(v==s) {printf("%d",v);return;}
    DFS(s,pre[v]);
    printf(" %d",v);
}

int main(){
    fill(G[0],G[0]+maxn*maxn,INF);
    fill(c,c+maxn,INF);
    fill(d,d+maxn,INF);
    scanf("%d%d%d%d",&n,&m,&s,&de);
    int u,v,des,cs;
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&u,&v,&des,&cs);
        G[u][v]=G[v][u]=des;
        cost[u][v]=cost[v][u]=cs;
    }
    Dijkstra(s);
    DFS(s,de);
    printf(" %d",d[de]);
    printf(" %d",c[de]);
    return 0;
}
