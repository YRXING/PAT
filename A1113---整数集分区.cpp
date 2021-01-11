#include<cstdio>
#include<algorithm>
using namespace std;

const int N=100010;
int a[N],hashTable[N]={0};
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);

    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        if(i<n/2) sum1+=a[i];
        else sum2+=a[i];
    }
    if(n%2==0) printf("0 %d",sum2-sum1);
    else printf("1 %d",sum2-sum1);
    return 0;
}
