#include<stdio.h>
#include<algorithm>
using namespace std;

const int N=10010;
const int M = 110;
int coin[N],dp[M]={0};
bool choice[N][M],flag[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&coin[i]);
    }
    sort(coin+1,coin+n+1,cmp);
    for(int i=1;i<=n;i++)
    for(int v=m;v>=coin[i];v--){
        if(dp[v]<=dp[v-coin[i]]+coin[i]){
            dp[v]=dp[v-coin[i]]+coin[i];
            choice[i][v]= 1;
        }
        else choice[i][v]=0;
    }

    if(dp[m]!=m) printf("No Solution");
    else {
        int k=n,num=0,v=m;
        while(k>=0){
            if(choice[k][v]==1){
                flag[k]=true;
                v-=coin[k];
                num++;
            }else{
                flag[k]=false;
            }
            k--;
        }

        for(int i=n;i>=1;i--){
            if(flag[i]==true){
                printf("%d",coin[i]);
                num--;
                if(num>0) printf(" ");
            }
        }
    }

    return 0;
}
