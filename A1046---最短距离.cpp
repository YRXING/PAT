#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int A[N],dist[N];

int main(){
    int n,m,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        sum+=A[i];
        dist[i]=sum;//dist[i]表示到i+1的距离
    }
    scanf("%d",&m);
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        a--;b--;
        if(a>b) swap(a,b);
        int d=dist[b]-dist[a];
        printf("%d\n",min(d,sum-d));
    }
    return 0 ;
}
