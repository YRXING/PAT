#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct Node{//1.定义
    int adress;
    int key;
    int next;
    bool flag;//结点是否在链表上
}node[maxn];

bool cmp(Node a,Node b){
    if(a.flag==false||b.flag==false)
        return a.flag>b.flag;
    else return a.key<b.key;
}

int main(){
    int n,head;
    scanf("%d%d",&n,&head);
    for(int i=0;i<maxn;i++)//2.初始化
        node[i].flag=false;
    for(int i=0;i<n;i++){
        int adress;
        scanf("%d",&adress);
        scanf("%d%d",&node[adress].key,&node[adress].next);
        node[adress].adress=adress;
    }
    int count=0,p=head;
    while(p!=-1){//3.枚举，对flag标记，同时计数
        node[p].flag=true;
        p=node[p].next;
        count++;
    }
    if(count==0) printf("0 -1");//特判
    else{
        sort(node,node+maxn,cmp);//4.排序，筛选有效结点
        printf("%d %05d\n",count,node[0].adress);//5.输出
        for(int i=0;i<count;i++){
            if(i<count-1)
                printf("%05d %d %05d\n",node[i].adress,node[i].key,node[i+1].adress);
            else
                printf("%05d %d -1\n",node[i].adress,node[i].key);
        }
    }
    return 0;
}
/*
1.题目可能会有无效结点，即不在题目给出的首地址开始的链表上
2.数据里面还有全部是无效的情况，这时就要根据有效结点的个数特判输出“0-1”*/
