#include<stdio.h>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;
const int maxn = 1010;
struct node{
    int id;
    int layer;
};
vector<node> G[maxn];
bool inq[maxn]={false};

int n,l,k;
int BFS(int s,int L){
    int numForward=0;
    queue<node> q;
    node start;
    start.id=s;
    start.layer=0;
    q.push(start);
    inq[start.id]=true;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        int u = top.id;
        for(int i=0;i<G[u].size();i++){
            node next = G[u][i];
            next.layer = top.layer+1;
            if(inq[next.id]==false&&next.layer<=L){
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}

int main(){
    node user;
    scanf("%d%d",&n,&l);
    int num;
    for(int i=1;i<=n;i++){
        user.id=i;
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            int p;
            scanf("%d",&p);
            G[p].push_back(user);
        }
    }

    scanf("%d",&k);
    int query,peple;
    for(int i=0;i<k;i++){
        memset(inq,false,sizeof(inq));
        scanf("%d",&query);
        printf("%d\n",BFS(query,l));
    }
    return 0;
}
