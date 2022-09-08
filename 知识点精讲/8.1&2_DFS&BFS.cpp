/*DFS
1.深度优先搜索是一种枚举所有完整路径以遍历所有情况的搜索方法
2.递归中的递归式就是岔道口，递归边界就是死胡同，
  使用递归可以很好的实现深度优先搜索，其本质就是栈
*/
//背包问题：
//有n件物品，重量w[i],价值c[i]，在不超过背包容量V的前提下，求最大价值（1<=n<=20）
#include<stdio.h>
const int maxn=30;
int n,V,maxValue=0;
int w[maxn],c[maxn];
void DFS(int index,int sumW,int sumC){
    if(index==n){//已经完成对n件物品的选择（死胡同）
        if(sumW<=V&&sumC>maxValue) maxValue = sumC;
        return ;
    }
    //岔道口
    DFS(index+1,sumW,sumC)//不选第index件物品
    DFS(index+1,sumW+w[index],sumC+c[index]);//选第index件物品
}
//复杂度O(2^n)

//只有当sunW<=V时才进入岔道口以及更新最大价值(剪枝)
void DFS(int index,int sumW,int sumC){
    if(index == n) return;
    DFS(index+1,sumW,sumC)//不选第index件物品
    if(sumW+w[index]<=V){
        if(sumC+c[index]>ans){
            ans = sumc+c[index];//更新最大价值maxValue
        }
        DFS(index+1,sumW+w[index],sumC+c[index]);//选第index件物品
    }
}

/*可以解决的问题：
1.给定一个序列，枚举这个序列的所有子序列
2.枚举从N个整数中选择K个数的所有方案
*/

//给定N个整数，选择K个数，使得这K个数之和恰好等于X，如果有多种方案，选择他们中元素平方和最大的一个
int n,k,x,maxSumSqu=-1,A[maxn];
//temp存放临时方案，ans存放最大方案
vector<int >temp,ans;
void DFS(int index,int nowK,int sum,int sumSqu){
    if(nowK==k&&sum==x){
        if(sumSqu>maxSumSqu){
            maxSumSqu=sumSqu;
            ans=temp;
        }
        return;
    }
    if(index==n||nowK>k||sum>x) return;
    temp.push_back(A[index]);//选index号数
    DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
    temp.pop_back();
    DFS(index+1,nowK,sum,sumSqu);//不选index号数
}

//BFS
//BFS中每个节点只入队一次,STL中的push的一个副本
//因此如果需要修改元素，队列中应存放元素的编号(如果是数组则存放下标)
void BFS(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        //取出队首元素top;
        //访问队首元素top；
        //将对手元素出队;
        //将top的下一层节点中未曾入队的结点全部入队，并设置已入队
    }
}

//求联通块
#include<cstdio>
#include<queue>
using namespace std;

const int maxn=100;
struct node{
    int x,y;
}Node;

int m,n;
int matrix[maxn][maxn];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
bool inq[maxn][maxn]={false};

bool juge(int x,int y){//判断(x,y)是否需要访问
    //越界返回false
    if(x>=n||x<0||y>=m||y<0) return false;
    if(matrix[x][y]==0||inq[x][y]==true) return false;
    return true;
}

void BFS(int x,int y){//BFS访问x,y所在的块
    queue<node> Q;
    Node.x=x;Node.y=y;
    Q.push(Node);
    inq[x][y]=true;
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int newX = top.x+X[i];
            int newY = top.x+Y[i];
            if(juge(newX,newY)){
                Node.x=x,Node.y;
                Q.push(Node);
                inq[newX][newY]=true;
            }
        }
    }
}

/* 给定一个n*m大小的迷宫，其中*代表不可通过的墙壁，'.'代表平地，S代表起点，T代表终点，求S到达T最少步数
输入：
5 5
. . . . .
. * . * .
. * S * .
. * * * .
. . . T *
该题用DFS不好做，DFS遍历到T时候步数不一定是最少的，因此需要维护个最少变量，当到达T时候不断去更新。
而用BFS的好处是，每次只往前遍历一层，一层一层往前走，如果到达T，那么一定是最少的步数，可以直接返回！！！
*/
struct node {
  int x, y;
  int step;
}S,T,Node;
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};
int n,m; // 行和列
int maze[maxn][maxn];//迷宫信息
int vis[maxn][maxn]={false};
bool judge(int x,int y){
  if(x>=n||x<0||y>=m||y<0) return false;
  if(maze[x][y] == '*'|| vis[x][y]) return false;
  return true;
}

int BFS(){
  queue<node> q;
  q.push(S);
  while(!q.empty()){
    node top = q.front();
    q.pop();
    if(top.x == T.x&&top.y==T.y) return top.step; //一定是最少的步数，直接返回
    for(int i=0;i<4;i++){
      int newX = top.x+X[i];
      int newY = top.y+Y[i];
      if(judge(newX,newY)){
        Node.x = newX,Node.y = newY;
        Node.step = top.step + 1;
        q.push(Node);
        vis[newX][newY] = true;
      }
    }
  }
  return -1; // 无法到达终点T返回-1
}

int main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    getchar();//过滤掉每行后面的换行符
    for(int j=0;j<m;j++) maza[i][j]=getchar();
    
   maza[i][m+1]='\0';
  }
  scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
  S.step=0;
  printf("%d\n",BFS());
}
