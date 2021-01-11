#include<stdio.h>
#include<queue>
using namespace std;
const int N=1010;
struct node{
    int data;
    node *lchild,*rchild;
    int level;
}*tree;
queue<node*> Q;
int maxlevel=0,n1=0,n2=0;
void insert(node * &root,int x){
    if(root==NULL){
        root = new node;
        root->data=x;
        root->lchild=root->rchild=NULL;
        return;
    }
    if(x<=root->data) insert(root->lchild,x);
    else insert(root->rchild,x);
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    Q.push(root);
    root->level=1;
    while(!q.empty()){
        node* top=q.front();
        q.pop();
        if(top->level>maxlevel) maxlevel=top->level;
        if(top->lchild){
            top->lchild->level=top->level+1;
            q.push(top->lchild);
            Q.push(top->lchild);
        }
        if(top->rchild){
            top->rchild->level=top->level+1;
            q.push(top->rchild);
            Q.push(top->rchild);
        }
    }
}

void calNodes(){
    while(!Q.empty()){
        node* top=Q.front();
        Q.pop();
        if(top->level==maxlevel) n1++;
        else if(top->level==(maxlevel-1)) n2++;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        insert(tree,x);
    }
    bfs(tree);
    calNodes();
    printf("%d + %d = %d",n1,n2,n1+n2);
    return 0;
}
