#include<stdio.h>

const int maxn=1010;
int G[maxn][maxn]={0};
int n,m,k;
bool vis[maxn]={false};

void DFS(int u,int k){
    vis[u]=true;
    for(int v=1;v<=n;v++){
        if(v==k) continue;
        else if(G[u][v]&&vis[v]==false) DFS(v,k);
    }
}

int need(int k){
    int ans=0;
    for(int u=1;u<=n;u++){
        if(u==k) continue;
        else if(vis[u]==false){
            ans++;
            DFS(u,k);
        }
    }
    return ans-1;
}

void reset(){
    for(int i=0;i<maxn;i++) vis[i] = false;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int v,u;
        scanf("%d%d",&u,&v);
        G[u][v]=G[v][u]=1;
    }
    for(int i=0;i<k;i++){
        reset();
        int v;
        scanf("%d",&v);
        printf("%d\n",need(v));
    }
    return 0;
}
