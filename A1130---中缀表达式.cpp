#include<cstdio>
const int N=30;
struct node{
    char data[10];
    int left,right;
}tree[N];

int notRoot[N]={0},r;

void inOrder(int root){
    if(root==-1) return;
    if(root!=r&&(tree[root].left!=-1||tree[root].right!=-1))
        printf("(");
    inOrder(tree[root].left);
    printf("%s",tree[root].data);
    inOrder(tree[root].right);
    if(root!=r&&(tree[root].left!=-1||tree[root].right!=-1))
        printf(")");
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s%d%d",tree[i].data,&tree[i].left,&tree[i].right);
        notRoot[tree[i].left]=notRoot[tree[i].right]=1;
    }

    for(int i=1;i<N;i++){
        if(!notRoot[i]){r=i;break;}
    }

    inOrder(r);
    return 0;
}
