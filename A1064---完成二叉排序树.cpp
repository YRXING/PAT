#include<stdio.h>
#include<algorithm>
using namespace std;

const int N = 1010;
int CBT[N];
int in[N];
int num=0,n;
void inOrder(int root){
    if(root>n) return;
    inOrder(root*2);
    CBT[root]=in[num++];
    inOrder(root*2+1);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    sort(in,in+n);
    inOrder(1);
    for(int i=1;i<=n;i++){
        printf("%d",CBT[i]);
        if(i<n) printf(" ");
    }
    return 0;
}
