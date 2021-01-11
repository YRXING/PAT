#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
const int N=50;
struct node{
    int data;
    node *lchild,*rchild;
    int level;
}*tree;

queue<node*> Q;
stack<node*> S;
int post[N],in[N],isfirst=1;

node* create(int postL,int postR,int inL,int inR){
    if(inL>inR) return NULL;
    node* root=new node;
    root->data=post[postR];
    int k;
    for(k=inL;k<=inR;k++){
        if(in[k]==post[postR]) break;
    }
    int numleft=k-inL;
    root->lchild=create(postL,postL+numleft-1,inL,k-1);
    root->rchild=create(postL+numleft,postR-1,k+1,inR);
    return root;
}

void printNode(node* root){
    if(isfirst) {printf("%d",root->data);isfirst=0;}
    else printf(" %d",root->data);
}

void calLevel(node* root){
    queue<node*> q;
    q.push(root);
    Q.push(root);
    root->level=1;
    while(!q.empty()){
        node* top=q.front();
        q.pop();
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

void zigZag(node* root){
    while(!Q.empty()){
        node* top = Q.front();
        if(top->level%2==0){
            printNode(top);
            Q.pop();
        }
        else{
            int level = top->level;
            while(!Q.empty()&&Q.front()->level==level){
                S.push(Q.front());
                Q.pop();
            }
            while(!S.empty()){
                printNode(S.top());
                S.pop();
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&in[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    tree=create(0,n-1,0,n-1);
//    printf("%d",tree->data);
    calLevel(tree);
    zigZag(tree);
    return 0;
}
//后序中序序列读反，导致建树出错
