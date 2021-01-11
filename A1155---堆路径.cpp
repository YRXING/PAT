#include<stdio.h>
#include<vector>
using namespace std;
const int N=1010;
int heap[N];
int n,isMin=1,isMax=1;
vector<int> path;

void printPath(int x){
    if(x>n) return;
    if(x*2>n) {
        for(int i=0;i<path.size();i++){
            printf("%d ",path[i]);
        }
        printf("%d\n",heap[x]);
        return;
    }

    else path.push_back(heap[x]);
    printPath(x*2+1);
    printPath(x*2);
    path.pop_back();
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&heap[i]);
    printPath(1);
    for(int i=2;i<=n;i++){
        if(heap[i/2]>heap[i]) isMin=0;
        if(heap[i/2]<heap[i]) isMax=0;
    }
    if(isMin==1) printf("Min Heap");
    else printf("%s",isMax==1?"Max Heap":"Not Heap");
    return 0;
}
