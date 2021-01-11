#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}
const int N = 100010;
int nc[N]={};
int np[N]={};

int main(){
    int lenc,lenp;
    scanf("%d",&lenc);
    for(int i=0;i<lenc;i++)
        scanf("%d",&nc[i]);
    sort(nc,nc+lenc,cmp);
    scanf("%d",&lenp);
    for(int i=0;i<lenp;i++)
        scanf("%d",&np[i]);
    sort(np,np+lenp,cmp);

    int sum=0,pi=0,ci=0;
    while(pi<lenp&&ci<lenc){
        if(np[pi]>=0&&nc[ci]>=0){
            sum+=np[pi]*nc[ci];
        }
        if(np[lenp-1-pi]<0&&nc[lenc-1-ci]<0)
            sum+=np[lenp-1-pi]*nc[lenc-1-ci];
        pi++;ci++;

    }
    printf("%d",sum);
    return 0;
}
