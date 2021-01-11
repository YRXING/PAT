#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1020;
const int INF=1000000000;
int G[N][N],d[N];
bool vis[N]={false};
int n,m,k,ds;


void Dijkstra(int s){
    fill(vis,vis+N,false);
    fill(d,d+N,INF);
    d[s]=0;
    for(int i=0;i<n+m;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n+m;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=1;v<=n+m;v++){
            if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
                d[v]=d[u]+G[u][v];
            }
        }
    }
    return;
}

int strTonum(char str[]){
    int i=0,len=strlen(str),ID=0;
    while(i<len){
        if(str[i]!='G')
            ID = ID*10+str[i]-'0';
        i++;
    }
    if(str[0]=='G') return n+ID;
    else return ID;
}


int main(){
    fill(G[0],G[0]+N*N,INF);
    scanf("%d%d%d%d",&n,&m,&k,&ds);
    int u,v,dest;
    char c1[5],c2[5];
    for(int i=0;i<k;i++){
        scanf("%s %s %d",c1,c2,&dest);
        u=strTonum(c1);
        v=strTonum(c2);
        G[u][v]=G[v][u]=dest;
    }

    int k=-1;
    double ansDis=-1,ansAvg=INF;
    for(int i=n+1;i<=n+m;i++){
        Dijkstra(i);
        double minDis=INF,avg=0;
        for(int j=1;j<=n;j++){
            if(d[j]>ds){
                minDis=-1;
                break;
            }
            if(d[j]<minDis) minDis=d[j];
            avg+=1.0*d[j]/n;
        }
        if(minDis==-1) continue;
        if(minDis>ansDis){
            k=i;ansDis=minDis;ansAvg=avg;
        }else if(minDis==ansDis&&avg<ansAvg){
            k=i;ansAvg=avg;
        }
    }

    if(k==-1) printf("No Solution");
    else {
        printf("G%d\n",k-n);
        printf("%.1f %.1f",ansDis,ansAvg);
    }
    return 0;
}
