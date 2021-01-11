#include<stdio.h>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
vector<int> G[N];

bool isRoot[N];
int father[N];
int findFather(int x){
    int a = x;
    while(x!=father[x]) x = father[x];
    while(a!=father[a]){
        int z = a;
        a= father[a];
        father[z]=x;
    }
    return x;
}

void Union(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA!=faB) father[faA]=faB;
}
void init(int n){
    for(int i=1;i<=n;i++) father[i]=i;
}

int calBlock(int n){//计算连通块数
    int Block=0;
    for(int i=1;i<=n;i++) isRoot[findFather(i)]=true;
    for(int i=1;i<=n;i++) Block+=isRoot[i];
    return Block;
}

int maxH=0;//最大高度
set<int> temp,Ans;//temp临时存放DFS的最远结点的结果，Ans保存答案

void DFS(int u,int Height,int pre){
    if(Height>maxH){
        temp.clear();
        temp.insert(u);
        maxH=Height;
    }else if(Height==maxH) temp.insert(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==pre) continue;
        DFS(v,Height+1,u);
    }
}

int main(){
    int a,b,n;
    scanf("%d",&n);
    if(n==1) {printf("1");return 0;}
    init(n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a,b);
    }
    int Block = calBlock(n);
    if(Block!=1)
        printf("Error: %d components\n",Block);
    else{
        DFS(1,1,-1);//从1号开始DFS，初始高度1;
        Ans = temp;
        set<int>::iterator it=Ans.begin();
        DFS(*it,1,-1);
        for(it=temp.begin();it!=temp.end();it++)
            Ans.insert(*it);
        it=Ans.begin();
        printf("%d\n",*(it++));
        for(;it!=Ans.end();it++){
            printf("%d\n",*it);
        }
    }
}
