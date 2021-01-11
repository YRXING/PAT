#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int N=40;
struct node{
    int data;
    node* lchild,*rchild;
};
vector<int> nodes;

void insert(node* &root,int x){
    if(root==NULL){
        root=new node;
        root->data=x;
        root->lchild=root->rchild=NULL;
    }
    else if(abs(x)>abs(root->data)) insert(root->rchild,x);
    else if(abs(x)<=abs(root->data)) insert(root->lchild,x);
    else return;
}

node* create(){
    node* root=NULL;
    int len=nodes.size();
    for(int i=0;i<len;i++){
        insert(root,nodes[i]);
    }
    return root;
}

bool juge1(node* root){
    if(root==NULL) return true;
    if(root->data<0){
        if(root->lchild!=NULL&&root->lchild->data<0) return false;
        if(root->rchild!=NULL&&root->rchild->data<0) return false;
    }
    return juge1(root->lchild)&&juge1(root->rchild);
}

int getNum(node* root){
    if(root==NULL) return 0;
    int l = getNum(root->lchild);
    int r = getNum(root->rchild);
    return root->data>0?max(l,r)+1:max(l,r);
}

bool juge2(node* root){
    if(root==NULL) return true;
    int l=getNum(root->lchild);
    int r = getNum(root->rchild);
    if(l!=r) return false;
    return juge2(root->lchild)&&juge2(root->rchild);
}
int main(){
    int k;
    scanf("%d",&k);
    int n,a;
    for(int i=0;i<k;i++){
        scanf("%d",&n);
        nodes.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            nodes.push_back(a);
        }
        if(nodes[0]<0) printf("No\n");
        else {
            node* tree=create();
            if(juge1(tree)&&juge2(tree)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
