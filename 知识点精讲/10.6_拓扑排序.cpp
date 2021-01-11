/*
1.定义一个队列Q，并把所有入度为0的结点加入队列
2.取队首结点，输出。然后删去所有从它出发的边，并令这些边到达的顶点的入度减1.
  如果某个顶点的入度减为0，将其加入队列
3.反复进行2操作，直到队列为空。如果队列为空时入过队的结点数目恰好为N，说明拓扑序列成功
*/
vector<int> G[maxv];
int n,m,inDegree[maxv];

bool topologicalSort(){
    int num=0;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(inDegree[i]==0) q.push(i);
    } //1.

    while(!q.empty()){//2.
        int u=q.front();
        //print("%d",u);
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            inDegree[v]--;
            if(inDegree[v]==0) q.push(v);
        }
        G[u].clear();//清空顶点u的所有出边(如无必要,可不写)
        num++;
    }
    if(num==n) return true;
    else return false;
}
