#include<cstdio>
#include<queue>
using namespace std;

const int maxn = 30;
struct node{
    int data;
    node* lchild;
    node* rchild;
}*root;
int post[maxn],in[maxn];
int n;
node* create(int PostL,int PostR,int inL,int inR){
    if(PostL>PostR) return NULL;
    node* root = new node;
    root->data = post[PostR];
    int k;
    for(k=0;k<inR;k++){
        if(in[k]==post[PostR])
            break;
    }
    root->lchild = create(PostL,PostL+k-inL-1,inL,k-1);
    root->rchild = create(PostL+k-inL,PostR-1,k+1,inR);
    return root;
}
void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        if(now->lchild!=NULL) q.push(now->lchild);
        if(now->rchild!=NULL) q.push(now->rchild);
        if(q.empty()) printf("%d",now->data);
        else printf("%d ",now->data);
    }
}
int main(){
    scanf("%d",&n);
    root=NULL;
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&in[i]);
    root = create(0,n-1,0,n-1);
    levelOrder(root);
    return 0;
}
