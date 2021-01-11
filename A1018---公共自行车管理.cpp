#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int maxn=510;
const int INF = 1000000000;


int capacity,n,s,m,numPath=0,G[maxn][maxn],weight[maxn];
bool vis[maxn]={false};

int d[maxn], minNeed = INF,minRemain = INF;
vector<int> pre[maxn],tempPath,path;//��ʱ·��������·��


void Dijkstra(int s){
    fill(d,d+maxn,INF);
    d[s]=0;

    for(int i=0;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<=n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;

        for(int v=0;v<=n;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u]+G[u][v]==d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v){
    if(v==0){//�ݹ�߽�,Ҷ�ӽ��
        tempPath.push_back(v);
        int need=0,remain=0;
        for(int i=tempPath.size()-1;i>=0;i--){//�˴��赹��ö��
            int id = tempPath[i];
            if(weight[id]>0) remain+=weight[id];//��Ȩ����0��˵����Ҫ����
            else{
                if(remain>abs(weight[id])) remain-=abs(weight[id]);//���㹻���Ĳ���
                else {need+=abs(weight[id])-remain;remain=0;}//��������PMBCЯ��
            }
        }
        if(need<minNeed){
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        }
        else if(need==minNeed&&remain<minRemain){
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();i++) DFS(pre[v][i]);
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d",&capacity,&n,&s,&m);
    fill(G[0],G[0]+maxn*maxn,INF);
    for(int i=1;i<=n;i++) {
        scanf("%d",&weight[i]);
        weight[i]-=capacity/2;
    }

    for(int i=0;i<m;i++){
        int u,v,time;
        scanf("%d%d%d",&u,&v,&time);
        G[u][v]=G[v][u]=time;
    }
    Dijkstra(0);
    DFS(s);
    printf("%d ",minNeed);
    for(int i=path.size()-1;i>=0;i--){
        printf("%d",path[i]);
        if(i>0) printf("->");
    }
    printf(" %d",minRemain);
    return 0;
}
