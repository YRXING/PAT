#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

const int N=110;
struct node{
    int data;
    int lchild,rchild;
}Nodes[N];
int n,inSeq[N],num=0;

void inOrder(int root){
    if(root==-1) return;
    inOrder(Nodes[root].lchild);
    Nodes[root].data=inSeq[num++];
    inOrder(Nodes[root].rchild);
}

void levelOrder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int ad = q.front();
        q.pop();
        if(Nodes[ad].lchild!=-1) q.push(Nodes[ad].lchild);
        if(Nodes[ad].rchild!=-1) q.push(Nodes[ad].rchild);
        if(q.empty()) printf("%d",Nodes[ad].data);
        else printf("%d ",Nodes[ad].data);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        Nodes[i].lchild=l;
        Nodes[i].rchild=r;
    }
    int data;
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        inSeq[i]=data;
    }
    sort(inSeq,inSeq+n);
    inOrder(0);
    levelOrder(0);
    return 0;
}
