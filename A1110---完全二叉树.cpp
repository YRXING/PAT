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
void preOrder(int now,int seq){//seq��ÿ���������ȫ�������϶�Ӧ�ı��
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
1.������
2.�ҵ�δ���ֹ��Ľڵ�Ϊ��
3.�ж�,ͨ��ǰ������۲�ڵ������Ƿ�ʼ���ڸ���ֵ����
*/
