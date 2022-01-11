/*迪杰斯特拉算法思想
Dijkstra(G,d[],s){
    初始化;
    for(循环n次){
        u=使d[u]最小的还未被访问的顶点标号;
        记u已被访问;
        for(从u出发能到达的所有顶点v){
            if(v未被访问&&以u为中介点使s到顶点v的最短距离d[v]更优)
                优化d[v];
        }
    }
}
*/

const int maxn = 1000;
const int INF = 1000000000;

//邻接矩阵版
//需要枚举所有顶点来查看v是否可由u到达；邻接表则可以直接得到u能到达的顶点v

//求最短路径本身，只需在优化的那一部分令v的前驱为u
int n,G[maxn][maxn];
int d[maxn];
//int pre[maxn];//pre[v]表示从起点到顶点v最短路径上v的前一个顶点
bool vis[maxn]={false};

void Dijkstra(int s){ //s为起点
    fill(d,d+maxn,INF);
    //for(int i=0;i<n;i++) pre[i]=[i];//初始状态设每个点的前驱为自身
    d[s]=0;
    for(int i=0;i<n;i++){//循环n次
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){//选择这一趟中未被访问且d最小的点
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;//找不到，说明剩下的点和起点s不连通

        vis[u]=true;
        // 以u为节点开始优化路径
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v])
                d[v]=d[u]+G[u][v];
                //pre[v]=u;
        }
    }
}

void DFS(int s,int v){//从终点开始递归
    if(v==s){
        printf("%d\n",s);
        return;
    }
    DFS(s,pre[v]);
    printf("%d\n",v);
}

//如果有多条路径需要打印
vector<int> pre[maxn],path;
for(int v=0;v<n;v++){
    if(vis[v]==false&&G[u][v]!=INF){
        if(d[u]+G[u][v]<d[v]){
            d[v] =d[u]+G[u][v];
            pre[v].clear();
            pre[v].push_back(u);
        }else if(d[u]+G[u][v]==d[v])
                pre[v].push_back(u);
    }
}

void DFS(int s,int v){
    //---核心代码
    if(v==s){
        path.push_back(v);
        for(int i=0;i<path.size();i++)
            printf(path[i]);
        path.pop_back();
        return;
    }
    //------
    path.push_back(v);
    for(int i=0;i<pre[v].size();i++) DFS(s,pre[v][i]);
    path.pop_back();//回溯
}

//邻接表版
struct node{
    int v,dis;//v为边的目标顶点，dis为边权
};
vector<node> Adj[maxn];
int n;
int d[maxn];
bool vis[maxn]={false};

void Djkstra(int s){
    fill(d,d+maxn,INF);
    d[s]=0;
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

        for(int j=0;j<Adj[u].size();j++){
            int v = Adj[u][j].v;
            if(vis[v]==false&&d[u]+Adj[u][j].dis<d[v]){
                d[v]=d[u]+Adj[u][j].dis;
            }
        }
    }
}

/*往往考试，最短路径不止一条，题目会给出一个第二标尺，
要求在所有最短路径中选择第二标尺最优的一条路径，常见三种出题方式
1.给每条边增加一个边权（比如说花费）,然后要求最短路径有多条时路径上
的花费最小（如果有其他含义，也可以是花费最大）
用cost[u][v] 代表花费，(题目输入)增加数组c[],领从起点s到u的最少花费为c[u],
初始化c[s]=0,其余均为INF
for(int v=0;v<n;v++){
    if(vis[v]==false&&G[u][v]!=INF){
        if(d[u]+G[u][v]<d[v]){
            d[v] = d[u]+G[u][v];
            c[v] = c[u]+cost[u][v];
        }
        else if(d[u]+G[u][v]==d[v]&&c[u]+c[u][v]<c[v])
            c[v] = c[u]+cost[u][v];
    }
}

2.给每一个点增加一个点权（例如每个城市能收集到的物资），然后在
最短路径有多条时路径上的点权之和最大（或最小）
用weight[u]表示u中的物资数目(题目输入),增加数组w[],从s到u的最大物资为w[u],
初始化w[s]=weight[s],其他为0
for(int v=0;v<n;v++){
    if(vis[v]==false&&G[u][v]!=INF){
        if(d[u]+G[u][v]<d[v]){
            d[v] = d[u]+G[u][v];
            w[v] = w[u]+weight[v];
        }else if(d[u]+G[u][v]==d[v]&&w[u]+weight[v]>w[v])
            w[v] = w[u]+weight[v];
    }
}

3.求最短路径条数。
增加数组num[]，从s到u的最短路径条数为num[u]
初始化num[s]=1,其余为0
for(int v=0;v<n;v++){
    if(vis[v]==false&&G[u][v]!=INF){
        if(d[u]+G[u][v]<d[v]){
            d[v]=d[u]+G[u][v];
            num[v] = num[u];
        }else if(d[u]+G[u][v]==d[v])
            num[v]+=num[u];
    }
}

上述还可以用Dijkstra+DFS的写法，所有最短路径保存起来，DFS每一条tempPath
计算出该路径上最小的边权之和或最大的点权之和，然后令其与 边权minCost比较，
如果新路径的边权之和更小，则更新minCost和最优路径path：
if(v==st){
    tempPath.push_back(v);
    int tempCost=0;
    for(int i=tempPath.size()-1;i>0;i--){
        int id = tempPath[i],idNext = tempPath[i-1];
        tempCost+=cost[id][next];
    }
    if(tempCost<minCost){
        minCost = tempCost;
        path = tempPath;
    }
    tempPath.pop_back();
    return;
}
