#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=25;

struct node{
    int lchild,rchild;
}Nodes[N];

int n,flag=0,MAX;

int toInt(char str[]){
    if(strlen(str)==1) return str[0]-'0';
    else return (str[0]-'0')*10+str[1]-'0';
}
int Exit[N]={0};
void preOrder(int now,int seq){//seq是每个结点在完全二叉树上对应的编号
    if(flag||now==-1) return;
    if(seq>n){
        flag=1;
        return;
    }else if(seq==n){
        MAX=now;
    }
    preOrder(Nodes[now].lchild,seq*2);
    preOrder(Nodes[now].rchild,seq*2+1);
}

int main(){
    scanf("%d",&n);
    char l[3],r[3];

    for(int i=0;i<n;i++){
        scanf("%s%s",l,r);
        if(l[0]=='-') Nodes[i].lchild=-1;
        else {Nodes[i].lchild=toInt(l);Exit[toInt(l)]=1;}
        if(r[0]=='-') Nodes[i].rchild=-1;
        else {Nodes[i].rchild=toInt(r);Exit[toInt(r)]=1;}
    }

    int root;
    for(int i=0;i<n;i++){
        if(Exit[i]==0){root=i;break;}
    }
    preOrder(root,1);
    if(flag) printf("NO %d\n",root);
    else printf("YES %d\n",MAX);
    return 0;
}

/*
1.读入树
2.找到未出现过的节点为根
3.判断,通过前序遍历观察节点的序号是否始终在给定值以内
*/
