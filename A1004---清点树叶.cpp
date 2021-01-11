#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=110;
vector<int> tree[N];
int leaf[N]={0};
int h[N]={0};
int n,m,level=0;
void BFS(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        level = max(level,h[u]);
        if(tree[u].size()==0) leaf[h[u]]++;
        for(int i=0;i<tree[u].size();i++){
            h[tree[u][i]] = h[u]+1;
            q.push(tree[u][i]);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    int k,id,child;
    for(int i=0;i<m;i++){
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&child);
            tree[id].push_back(child);
        }
    }
    h[1]=1;//初始化根节点
    BFS(1);
    for(int i=1;i<=level;i++){
        printf("%d",leaf[i]);
        if(i<level) printf(" ");
    }

    return 0;
}
