#include<stdio.h>
#include<vector>
using namespace std;

const int N=510;
int vis[N]={0};
vector<int> G[N];

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]==0) dfs(v);
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
            ans++;
        }
    }
    int odd=0;
    for(int i=1;i<=n;i++){
        if(G[i].size()%2!=0) odd++;
        printf("%d",G[i].size());
        if(i<n) printf(" ");
    }

    if(ans>1) {
        printf("\nNon-Eulerian");
    }

    else if(odd==0)
        printf("\nEulerian");
    else if(odd==2)
        printf("\nSemi-Eulerian");
    else printf("\nNon-Eulerian");
    return 0;
}

/*
第三个测试点错误原因：
题目说明：connected graphs 因此先判断是否是连通图
*/
