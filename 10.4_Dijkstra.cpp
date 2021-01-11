/*�Ͻ�˹�����㷨˼��
Dijkstra(G,d[],s){
    ��ʼ��;
    for(ѭ��n��){
        u=ʹd[u]��С�Ļ�δ�����ʵĶ�����;
        ��u�ѱ�����;
        for(��u�����ܵ�������ж���v){
            if(vδ������&&��uΪ�н��ʹs������v����̾���d[v]����)
                �Ż�d[v];
        }
    }
}
*/

const int maxn = 1000;
const int INF = 1000000000;

//�ڽӾ����
//��Ҫö�����ж������鿴v�Ƿ����u����ڽӱ������ֱ�ӵõ�u�ܵ���Ķ���v

//�����·������ֻ�����Ż�����һ������v��ǰ��Ϊu
int n,G[maxn][maxn];
int d[maxn];
//int pre[maxn];//pre[v]��ʾ����㵽����v���·����v��ǰһ������
bool vis[maxn]={false};

void Dijkstra(int s){ //sΪ���
    fill(d,d+maxn,INF);
    //for(int i=0;i<n;i++) pre[i]=[i];//��ʼ״̬��ÿ�����ǰ��Ϊ����
    d[s]=0;
    for(int i=0;i<n;i++){//ѭ��n��
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){//ѡ����һ����δ��������d��С�ĵ�
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;//�Ҳ�����˵��ʣ�µĵ�����s����ͨ

        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v])
                d[v]=d[u]+G[u][v];
                //pre[v]=u;
        }
    }
}

void DFS(int s,int v){//���յ㿪ʼ�ݹ�
    if(v==s){
        printf("%d\n",s);
        return;
    }
    DFS(s,pre[v]);
    printf("%d\n",v);
}

//����ж���·����Ҫ��ӡ
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
    //---���Ĵ���
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
    path.pop_back();//����
}

//�ڽӱ��
struct node{
    int v,dis;//vΪ�ߵ�Ŀ�궥�㣬disΪ��Ȩ
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
            int v = Adj[u][i];
            if(vis[v]==false&&d[u]+Adj[u][j].dis<d[v]){
                d[v]=d[u]+Adj[u][j].dis;
            }
        }
    }
}

/*�������ԣ����·����ֹһ������Ŀ�����һ���ڶ���ߣ�
Ҫ�����������·����ѡ��ڶ�������ŵ�һ��·�����������ֳ��ⷽʽ
1.��ÿ��������һ����Ȩ������˵���ѣ�,Ȼ��Ҫ�����·���ж���ʱ·����
�Ļ�����С��������������壬Ҳ�����ǻ������
��cost[u][v] �����ѣ�(��Ŀ����)��������c[],������s��u�����ٻ���Ϊc[u],
��ʼ��c[s]=0,�����ΪINF
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

2.��ÿһ��������һ����Ȩ������ÿ���������ռ��������ʣ���Ȼ����
���·���ж���ʱ·���ϵĵ�Ȩ֮����󣨻���С��
��weight[u]��ʾu�е�������Ŀ(��Ŀ����),��������w[],��s��u���������Ϊw[u],
��ʼ��w[s]=weight[s],����Ϊ0
for(int v=0;v<n;v++){
    if(vis[v]==false&&G[u][v]!=INF){
        if(d[u]+G[u][v]<d[v]){
            d[v] = d[u]+G[u][v];
            w[v] = w[u]+weight[v];
        }else if(d[u]+G[u][v]==d[v]&&w[u]+weight[v]>w[v])
            w[v] = w[u]+weight[v];
    }
}

3.�����·��������
��������num[]����s��u�����·������Ϊnum[u]
��ʼ��num[s]=1,����Ϊ0
for(int v=0;v<n;v++){
    if(vis[v]==false&&G[u][v]!=INF){
        if(d[u]+G[u][v]<d[v]){
            d[v]=d[u]+G[u][v];
            num[v] = num[u];
        }else if(d[u]+G[u][v]==d[v])
            num[v]+=num[u];
    }
}

������������Dijkstra+DFS��д�����������·������������DFSÿһ��tempPath
�������·������С�ı�Ȩ֮�ͻ����ĵ�Ȩ֮�ͣ�Ȼ�������� ��ȨminCost�Ƚϣ�
�����·���ı�Ȩ֮�͸�С�������minCost������·��path��
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
