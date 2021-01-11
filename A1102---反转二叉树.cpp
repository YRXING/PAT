#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;

struct node{
    int lchild,rchild;
}Node[10];

int n,num=0;;
int hashTable[10]={0};

int toNum(char c){
    if(c=='-') return -1;
    else {
        hashTable[c-'0']=1;
        return c-'0';
    }
}

int findRoot(){
    for(int i=0;i<n;i++)
        if(hashTable[i]==false)
        return i;
}

void print(int id){
    printf("%d",id);
    num++;
    if(num<n) printf(" ");
    else printf("\n");
}

void levelOrder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        print(now);
        if(Node[now].lchild!=-1) q.push(Node[now].lchild);
        if(Node[now].rchild!=-1) q.push(Node[now].rchild);
    }
}

void inOrder(int root){
    if(root==-1) return;
    inOrder(Node[root].lchild);
    print(root);
    inOrder(Node[root].rchild);
}

int main(){
    scanf("%d",&n);
    char r,l;
    for(int i=0;i<n;i++){
       scanf("%*c%c %c",&r,&l);
       Node[i].rchild=toNum(r);
       Node[i].lchild=toNum(l);
    }
    int root=findRoot();
    levelOrder(root);
    num=0;
    inOrder(root);
    return 0;
}

/*后序遍历反转二叉树
void postOrder(int root){
    if(root==-1) return;
    postOrder(Node[root].lchild);
    postOrder[Node[root].rchild];
    swap(Node[root].lchild,Node[root].rchild);
}*/
