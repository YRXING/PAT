#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
const int N=10010;
struct node{
    int data;
    node* lchild;
    node* rchild;
}*tree;

int m,n;
//int v1,v2,f1,f2;
map<int,int> key,depth,father;
stack<int> p1,p2;//两个结点的祖先
int pre[N],in[N];

node* create(int preL,int preR,int inL,int inR){
    if(preL>preR) return NULL;
    node* root=new node;
    root->data=pre[preL];
    int k;
    for(int i=inL;i<=inR;i++){
        if(in[i]==pre[preL]){
            k=i;
            break;
        }
    }
    int numleft=k-inL;
    root->lchild=create(preL+1,preL+numleft,inL,k-1);
    root->rchild=create(preL+numleft+1,preR,k+1,inR);
    return root;//不能忘记！！！！否则会出现段错误!!!
}

void dfs(int pre,node* rt){
    depth[rt->data]=depth[pre]+1;
    father[rt->data]=pre;
    if(rt->lchild) dfs(rt->data,rt->lchild);
    if(rt->rchild) dfs(rt->data,rt->rchild);

}

//void dfs(node *root){//递归树寻找根节点到给定结点的路径
//    if(!root) return;
//    if(f1) p1.push(root->data);
//    if(f2) p2.push(root->data);
//    if(root->data==v1) f1=0;
//    if(root->data==v2) f2=0;
//    dfs(root->lchild);
//    dfs(root->rchild);
//    if(f1) p1.pop();
//    if(f2) p2.pop();
//}

int LCA(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);
    while(depth[a]>depth[b]) a=father[a];
    while(a!=b){
        a=father[a];
        b=father[b];
    }
    return a;
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
        key[in[i]]=1;
    }
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);

    tree=create(0,n-1,0,n-1);
    depth[tree->data]=0;
    dfs(tree->data,tree);

    for(int i=0;i<m;i++){
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        if(key[v1]==0&&key[v2]==0)
            printf("ERROR: %d and %d are not found.\n", v1,v2);
        else if(key[v1]==0 || key[v2]==0)
            printf("ERROR: %d is not found.\n", key[v2]==0?v2:v1);
        else{
//              while(!p1.empty()) p1.pop();
//              while(!p2.empty()) p2.pop();
//              f1=f2=1;
//              dfs(tree);
//              while(p1.size()>p2.size()) p1.pop();
//              while(p2.size()>p1.size()) p2.pop();
//              while(p1.top()!=p2.top()){
//                    p1.pop();
//                    p2.pop();
//              }
//              if(p1.top()!=v1 && p1.top()!=v2)
//                    printf("LCA of %d and %d is %d.\n",v1,v2,p1.top());
//            else if(p1.top() == v1)
//                    printf("%d is an ancestor of %d.\n", v1,v2);
//            else    printf("%d is an ancestor of %d.\n", v2,v1);
            int fa=LCA(v1,v2);
            if(fa!=v1&&fa!=v2) printf("LCA of %d and %d is %d.\n",v1,v2,fa);
            else if(fa==v1) printf("%d is an ancestor of %d.\n",v1,v2);
            else printf("%d is an ancestor of %d.\n",v2,v1);
        }
    }
    return 0;
}
