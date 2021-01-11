#include<cstdio>
#include<algorithm>
using namespace std;

const int N=10010;
int a[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int sum=a[0];
    for(int i=1;i<n;i++){
        sum=(sum+a[i])/2;
    }
    printf("%d",sum);
    return 0;
}
