//图的存储
/*邻接矩阵
1.G[i][j]=1说明顶点i,j之间有边，G[i][j]还可以存放边的权
2.顶点数目不超过1000
*/

/*邻接表
1.可以用vector<int> Adj[N]
2.如果需要存放边权
  struct node{
    int v;
    int w;
    node(int _v,int _w):v(_v),w(_w){}
  };
  vector<node> Adj[N];
  Adj[1].push_back(node(3,4));//不需要定义临时变量
*/

//图的遍历
/*DFS思路
DFS(u){
    vis[u] = true;
    for(从u出发能到达的顶点v)
        if(vis[v]==fals) DFS(v);
}

DFSTravel(G){
    for(G中的所有顶点u)
        if(vis[u]==false) DFS(u);
}
*/

//邻接矩阵版
const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};

void DFS(int u,int depth){
    vis[u] = true;
    //...对u进行的操作
    for(int v=0;v<n;v++){
        if(vis[v]==false&&G[u][v]!=INF) DFS(v,depth+1);
    }
}
void DFSTravel(){
    for(int u =0;u<n;u++){
        if(vis[u]==false) DFS(u,1);
    }
}
//邻接表版
vector<int> Adj[MAXV];
int n;
bool vis[MAXV]={false};
void DFS(u){
    vis[u]=true;
    for(int i=0;i<Adj[u].size();i++){
        int v = Adj[u][i];
        if(vis[v]==false) DFS(v,depth+1);
    }
}
void DFSTravel(){
    for(int u=0;u<n;u++){
        if(vis[u]==false) DFS(u,1);
    }
}

//BFS
//邻接表版
int n,G[MAXV][MAXV];
bool inq[MAXV]={false};

void BFS(u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0;v<n;v++){
            if(inq[v]==false&&G[u][v]!=INF){
                q.push(v);
                inq[v]=true;
            }
        }
    }
}
void BFSTravel(){
    for(int u=0;u<n;u++){
        if(inq[u]==false) BFS(u);
    }
}

//邻接表版
vector<int> Adj[MAXV];
int n;
bool inq[MAXV]={false};
void BFS(u){
    queue<int> q;
    q.push(u);
    inq[u]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<Adj[u].size();i++){
            int v = Adj[u][i];
            if(inq[v]==false){
                q.push(v);
                inq[v]=true;
            }
        }
    }
}
void BFSTravel(){
    for(int u=0;u<n;u++){
        if(inq[u]==false) BFS(u);
    }
}

/*与树的BFS一样，可能需要layer，则
struct node{
    int v;
    int layer;
};
vector<node> Adj[N];*/
