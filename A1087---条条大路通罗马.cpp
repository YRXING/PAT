#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
const int N=210;
const int INF=1000000000;
int G[N][N],d[N],weight[N],numPath=0;
bool vis[N]={false};
int n,m,start,rom,maxW=0;
double maxAvg=0;
vector<int> pre[N],tempPath,path;
map<string,int> getID;
map<int,string> getName;


void Dijkstra(int s){
    fill(d,d+N,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){u=j;MIN=d[j];}
        }
        if(u==-1) return;
        vis[u]=true;

        for(int v=0;v<n;v++){
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
    if(v==0){
        tempPath.push_back(v);
        numPath++;
        int tempW=0;
        for(int i=tempPath.size()-2;i>=0;i--){
            int id = tempPath[i];
            tempW+=weight[id];
        }
        double tempAvg=1.0*tempW/(tempPath.size()-1);
        if(tempW>maxW){
            maxW = tempW;
            maxAvg = tempAvg;
            path = tempPath;
        }else if(tempW==maxW&&tempAvg>maxAvg){
            maxAvg = tempAvg;
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
    string start,city1,city2;
    fill(G[0],G[0]+N*N,INF);
    cin>>n>>m>>start;
    getID[start]=0;
    getName[0]=start;
    int happy,cost;
    for(int i=1;i<=n-1;i++){
        cin>>city1>>weight[i];
        getID[city1]=i;
        getName[i]=city1;
    }
    for(int i=0;i<m;i++){
        cin>>city1>>city2>>cost;
        int u=getID[city1],v=getID[city2];
        G[u][v]=G[v][u]=cost;
    }

    Dijkstra(0);
    rom = getID["ROM"];
    DFS(rom);
    printf("%d %d %d %d\n",numPath,d[rom],maxW,(int)maxAvg);
    for(int i=path.size()-1;i>=0;i--){
        cout<<getName[path[i]];
        if(i>0) printf("->");
    }
    return 0;
}
