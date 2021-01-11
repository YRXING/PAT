#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 100010;
struct Node{//1.定义
    int adress,data,next;
    int flag,order;
}node[maxn];
int hashTable[maxn]={0};
bool cmp(Node a,Node b){
    if(a.flag!=b.flag) return a.flag>b.flag;
    else return a.order<b.order;
}
int main(){
    int head,n;
    scanf("%d%d",&head,&n);
    for(int i=0;i<maxn;i++)//2.初始化
        node[i].order=maxn;
    for(int i=0;i<n;i++){
        int ad;
        scanf("%d",&ad);
        scanf("%d%d",&node[ad].data,&node[ad].next);
        node[ad].adress=ad;
    }
    //3.遍历，标记
    int p=head,count=0;
    while(p!=-1){
        if(hashTable[abs(node[p].data)]!=0) node[p].flag=0;
        else {node[p].flag=1; hashTable[abs(node[p].data)]=1;}
        node[p].order=count++;
        p=node[p].next;
    }
    sort(node,node+maxn,cmp);//4.排序
    //5.输出
    for(int i=0;i<count;i++){
        if(node[i].flag==1){
            if(node[i+1].flag==0) printf("%05d %d -1\n",node[i].adress,node[i].data);
            else printf("%05d %d %05d\n",node[i].adress,node[i].data,node[i+1].adress);
        }
        else if(node[i].flag==0){
            printf("%05d %d ",node[i].adress,node[i].data);
            if(i<count-1) printf("%05d\n",node[i+1].adress);
            else printf("-1");
        }
    }
    return 0;
}
