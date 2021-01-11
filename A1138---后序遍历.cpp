#include<stdio.h>

const int maxn=50010;
//struct node{
//    int v;
//    node *lchild,*rchild;
//}*tree;

int pre[maxn],in[maxn],f=1;

void Travel(int preL,int preR,int inL,int inR){
    if(preL>preR||!f) return;
//    node* root=new node;
//    root->v=pre[preL];
    int k;
    for(k=0;k<inR;k++)
        if(in[k]==pre[preL]) break;
    int numleft=k-inL;
//    root->lchild=create(preL+1,preL+numleft,inL,k-1);
//    root->rchild=create(preL+numleft+1,preR,k+1,inR);
    Travel(preL+1,preL+numleft,inL,k-1);
    Travel(preL+numleft+1,preR,k+1,inR);
    if(f){
        printf("%d",in[k]);
        f=0;
    }
//    return root;
}

//int flag=0;
//void dfs(node* root){
//    if(root==NULL) return;
//    if(root->lchild!=NULL) dfs(root->lchild);
//    if(root->rchild) dfs(root->rchild);
//    if(!flag){
//        printf("%d",root->v);
//        flag=1;
//    }else return;
//
//}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&in[i]);

    Travel(0,n-1,0,n-1);

    return 0;
}
