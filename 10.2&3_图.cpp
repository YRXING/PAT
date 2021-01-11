//ͼ�Ĵ洢
/*�ڽӾ���
1.G[i][j]=1˵������i,j֮���бߣ�G[i][j]�����Դ�űߵ�Ȩ
2.������Ŀ������1000
*/

/*�ڽӱ�
1.������vector<int> Adj[N]
2.�����Ҫ��ű�Ȩ
  struct node{
    int v;
    int w;
    node(int _v,int _w):v(_v),w(_w){}
  };
  vector<node> Adj[N];
  Adj[1].push_back(node(3,4));//����Ҫ������ʱ����
*/

//ͼ�ı���
/*DFS˼·
DFS(u){
    vis[u] = true;
    for(��u�����ܵ���Ķ���v)
        if(vis[v]==fals) DFS(v);
}

DFSTravel(G){
    for(G�е����ж���u)
        if(vis[u]==false) DFS(u);
}
*/

//�ڽӾ����
const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};

void DFS(int u,int depth){
    vis[u] = true;
    //...��u���еĲ���
    for(int v=0;v<n;v++){
        if(vis[v]==false&&G[u][v]!=INF) DFS(v,depth+1);
    }
}
void DFSTravel(){
    for(int u =0;u<n;u++){
        if(vis[u]==false) DFS(u,1);
    }
}
//�ڽӱ��
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
//�ڽӱ��
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

//�ڽӱ��
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

/*������BFSһ����������Ҫlayer����
struct node{
    int v;
    int layer;
};
vector<node> Adj[N];*/
