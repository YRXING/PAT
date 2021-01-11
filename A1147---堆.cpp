#include<stdio.h>
const int N=1010;
int heap[N];
int n,m,isMin,isMax,isfirst;

void postOrder(int x){
    if(x>n) return;
    postOrder(x*2);
    postOrder(x*2+1);
    if(isfirst) {printf("%d",heap[x]);isfirst=0;}
    else printf(" %d",heap[x]);
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
        isMin=isMax=1;
        isfirst=1;
        for(int i=1;i<=n;i++)
            scanf("%d",&heap[i]);
        for(int i=2;i<=n;i++){
            if(heap[i/2]>heap[i]) isMin=0;
            if(heap[i/2]<heap[i]) isMax=0;
        }
        if(isMax) printf("Max Heap\n");
        else printf("%s\n",isMin==1?"Min Heap":"Not Heap");
        postOrder(1);
        printf("\n");
    }
    return 0;
}
