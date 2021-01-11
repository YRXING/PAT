#include<cstdio>
#include<vector>
using namespace std;
const int maxn=510;
const int inf=(1<<30);
int n,m,st,ed,D[maxn],T[maxn],num_p[maxn],vis[maxn];	//D存放距离，T存放时间，num_p存放经过的结点数
struct node{
	int v,length,time;
	node(int a,int b,int c):v(a),length(b),time(c){}
};
vector<node> adj[maxn];
int pre1[maxn],pre2[maxn];
void dijkstra_D(int st){
	fill(D,D+n,inf);		//初始化
	fill(T,T+n,inf);		//初始化
	D[st]=0;
	for(int i=0;i<n;i++) pre1[i]=i;	//初始化
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(!vis[j]&&D[j]<min){
				u=j;
				min=D[j];
			}
		}
		if(u==-1) return ;
		vis[u]=1;
		for(int j=0;j<adj[u].size();j++){
			int v=adj[u][j].v,d=adj[u][j].length,t=adj[u][j].time;
			if(!vis[v]&&D[u]+d<D[v]){
				D[v]=D[u]+d;
				T[v]=T[u]+t;
				pre1[v]=u;
			}else if(!vis[v]&&D[u]+d==D[v]&&T[u]+t<T[v]){
				T[v]=T[u]+t;
				pre1[v]=u;
			}
		}
	}
}
void dijkstra_T(int st){
	fill(T,T+n,inf);
	fill(vis,vis+n,0);
	T[st]=0;
	for(int i=0;i<n;i++) pre2[i]=i;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(!vis[j]&&T[j]<min){
				u=j;
				min=T[j];
			}
		}
		if(u==-1) return ;
		vis[u]=1;
		for(int j=0;j<adj[u].size();j++){
			int v=adj[u][j].v,t=adj[u][j].time;
			if(!vis[v]&&T[u]+t<T[v]){
				T[v]=T[u]+t;
				pre2[v]=u;
				num_p[v]=num_p[u]+1;
			}else if(!vis[v]&&T[u]+t==T[v]&&num_p[u]+1<num_p[v]){
				num_p[v]=num_p[u]+1;
				pre2[v]=u;
			}
		}
	}
}
void DFS(int u,int tag){		//输出函数
	if(u==st){
		printf("%d",st);
		return;
	}
	if(tag==1)
		DFS(pre1[u],tag);
	else
		DFS(pre2[u],tag);
	printf(" -> %d",u);
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v,tag,length,time;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d%d",&u,&v,&tag,&length,&time);
		adj[u].push_back(node(v,length,time));
		if(!tag)		//tag==0表示为双向路径
			adj[v].push_back(node(u,length,time));
	}
	scanf("%d%d",&st,&ed);
	dijkstra_D(st);
	dijkstra_T(st);
	bool flag=true;
	for(int i=0;i<n&&flag;i++){
		if(pre1[i]!=pre2[i])
			flag=false;
	}
	if(flag){
		printf("Distance = %d; Time = %d: ",D[ed],T[ed]);
		DFS(ed,1);
	}else{
		printf("Distance = %d: ",D[ed]);
		DFS(ed,1);
		printf("\nTime = %d: ",T[ed]);
		DFS(ed,2);
	}
	return 0;
}
