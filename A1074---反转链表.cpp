#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 100010;
struct Node{//1.����
    int adress;
    int data;
    int next;
    int order;
}node[maxn];

bool cmp(Node a,Node b){
    return a.order<b.order;
}

int main(){
    for(int i=0;i<maxn;i++) node[i].order=maxn;//2.��ʼ��
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
    }//3.����,�ҳ�������Ч���

    sort(node,node+maxn,cmp);//4.����
    n=count;//Ϊ����д���㣬��count����n

    //5.�������Ѿ��γɣ����水����Ŀ����
    for(int i=0;i<n/k;i++){
        for(int j=(i+1)*k-1;j>i*k;j--)
            printf("%05d %d %05d\n",node[j].adress,node[j].data,node[j-1].adress);
        printf("%05d %d ",node[i*k].adress,node[i*k].data);
        if(i<n/k-1){
            printf("%05d\n",node[(i+2)*k-1].adress);
        }else{//�����һ��
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
