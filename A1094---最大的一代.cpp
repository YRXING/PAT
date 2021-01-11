#include<stdio.h>
#include<vector>
using namespace std;

const int N=100;
int n,m;
struct node{
    vector<int> child;
}Nodes[N];

int hashTable[N]={0};
void DFS(int root,int level){
    hashTable[level]++;
    for(int i=0;i<Nodes[root].child.size();i++){
        DFS(Nodes[root].child[i],level+1);
    }
}

int main(){
    int index,num,child;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&index,&num);
        for(int j=0;j<num;j++){
            scanf("%d",&child);
            Nodes[index].child.push_back(child);
        }
    }

    DFS(1,1);
    int maxlevel=0,total=-1;
    for(int i=1;i<=N;i++){
        if(hashTable[i]>total){
            total = hashTable[i];
            maxlevel=i;
        }
    }
    printf("%d %d",total,maxlevel);
}
//树的结构可以直接定义为vector<int> Node[maxn]
