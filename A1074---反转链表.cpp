#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 100010;
struct Node{//1.定义
    int adress;
    int data;
    int next;
    int order;
}node[maxn];

bool cmp(Node a,Node b){
    return a.order<b.order;
}

int main(){
    for(int i=0;i<maxn;i++) node[i].order=maxn;//2.初始化
    int first,n,k;
    scanf("%d%d%d",&first,&n,&k);

    for(int i=0;i<n;i++){
        int adress;
        scanf("%d",&adress);
        scanf("%d%d",&node[adress].data,&node[adress].next);
        node[adress].adress=adress;
    }

    int p=first,count=0;
    while(p!=-1){
        node[p].order=count++;
        p=node[p].next;
    }//3.遍历,找出所有有效结点

    sort(node,node+maxn,cmp);//4.排序
    n=count;//为了书写方便，把count赋给n

    //5.单链表已经形成，下面按照题目做题
    for(int i=0;i<n/k;i++){
        for(int j=(i+1)*k-1;j>i*k;j--)
            printf("%05d %d %05d\n",node[j].adress,node[j].data,node[j-1].adress);
        printf("%05d %d ",node[i*k].adress,node[i*k].data);
        if(i<n/k-1){
            printf("%05d\n",node[(i+2)*k-1].adress);
        }else{//是最后一块
            if(n%k==0) printf("-1");
            else{
                printf("%05d\n",node[(i+1)*k].adress);
                for(int i=n/k*k;i<n;i++){
                    printf("%05d %d ",node[i].adress,node[i].data);
                    if(i<n-1) printf("%05d\n",node[i+1].adress);
                    else printf("-1");
                }
            }
        }
    }
    return 0;
}
