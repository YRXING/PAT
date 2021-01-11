#include<stdio.h>

const int maxn = 100010;
struct Node{
    int adress;
    char data;
    int next;
    int falg;
}node[maxn];

int main(){
    int a1,a2,n;
    scanf("%d%d%d",&a1,&a2,&n);
    for(int i=0;i<maxn;i++)
        node[i].falg=0;
    for(int i=0;i<n;i++){
        int ad;
        scanf("%d ",&ad);
        scanf("%c %d",&node[ad].data,&node[ad].next);
        node[ad].adress=ad;
    }
    int p=a1;
    while(p!=-1){
        node[p].falg=1;
        p=node[p].next;
    }
    p=a2;
    while(!node[p].falg&&p!=-1){
        p=node[p].next;
    }
    if(p==-1) printf("-1");
    else printf("%05d",node[p].adress);
    return 0;
}
