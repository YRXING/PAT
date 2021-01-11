#include<stdio.h>
#include<algorithm>
using namespace std;

const int N = 100010;
int seq[N];

int main(){
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&seq[i]);
    }
    sort(seq,seq+n);
    int i=0,j=0,count = 1;
    while(i<n&&j<n){
        //j不断右移直到恰好不满足条件
        while(j<n&&seq[j]<=(long long)seq[i]*p){
            count = max(count,j-i+1);
            j++;
        }
        i++;
    }
    printf("%d",count);
    return 0;
}
//p与序列中的元素可能达到10^9，涉及乘法，所以用long long
