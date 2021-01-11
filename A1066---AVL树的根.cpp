#include<stdio.h>
#include<algorithm>
using namespace std;

struct node{
    int data,height;
    node* lchild,*rchild;
}*root;

int getHeight(node* root){
    if(root==NULL) return 0;
    else return root->height;
}

int getBalanceFactor(node* root){
    return getHeight(root->lchild)-getHeight(root->rchild);
}

void updateHeight(node* root){
    root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root,int x){
    if(root==NULL){
        root = new node;
        root->data = x;
        root->height = 1;
        root->lchild = root->rchild = NULL;
        return;
    }
    if(x<root->data){
        insert(root->lchild,x);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->lchild)==1) R(root);
            else if(getBalanceFactor(root->lchild)==-1) {L(root->lchild);R(root);}
        }
    }else{
        insert(root->rchild,x);
        updateHeight(root);
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->rchild)==-1) L(root);
            else if(getBalanceFactor(root->rchild)==1) {R(root->rchild);L(root);}
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        insert(root,data);
    }
    printf("%d",root->data);
    return 0;
}

//本题直接输出中位数也能得到不少分数
