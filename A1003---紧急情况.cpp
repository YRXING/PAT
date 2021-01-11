#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 500;
const int INF=1000000000;
int G[N][N];
bool vis[N]={false};
int num[N]={0};
int weight[N],w[N]={0},d[N];
int n,m,s,v;
void Dijkstra(int s){
    fill(d,d+N,INF);
    d[s]=0;
    num[s]=1;
    w[s]=weight[s];
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
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }else if(d[u]+G[u][v]==d[v]){
                    if(w[u]+weight[v]>w[v]) w[v]=w[u]+weight[v];
                    num[v]+=num[u];
                }
            }
        }
    }
}


int main(){
    scanf("%d%d%d%d",&n,&m,&s,&v);
    fill(G[0],G[0]+N*N,INF);
    for(int i=0;i<n;i++) scanf("%d",&weight[i]);
    for(int i=0;i<m;i++){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        G[a][b]=G[b][a]=d;
    }
    Dijkstra(s);
    printf("%d %d",num[v],w[v]);
    return 0;
}
//当d[u]+G[u][v]==d[v]时,无论w[u]+weight[v]>w[v]是否成立,都应当让num[v]+=num[u];
