#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;
const int maxn = 30;
int pre[maxn],in[maxn];
struct node{
    int data;
    node* lchild;
    node* rchild;
}*root;
int n,travle=0;

node* create(int preL,int preR,int inL,int inR){
    if(preL>preR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k=0;k<inR;k++){
        if(pre[preL]==in[k])
            break;
    }
    root->lchild = create(preL+1,preL+k-inL,inL,k-1);
    root->rchild = create(preL+k-inL+1,preR,k+1,inR);
    return root;
}

void postOrder(node* root){
    if(root==NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    if(travle==0) {printf("%d",root->data);travle++;}
    else printf(" %d",root->data);
}

int main(){
    scanf("%d",&n);
    char str[10];
    int precount=0,incount=0,num;
    stack<int> s;
    for(int i=0;i<n*2;i++){
        scanf("%s",str);
        if(strcmp(str,"Push")==0){
            scanf("%d",&num);
            pre[precount++]=num;
            s.push(num);
        }
        else {
            in[incount++]=s.top();
            s.pop();
        }
    }
    root = create(0,n-1,0,n-1);
    postOrder(root);
    return 0;
}
