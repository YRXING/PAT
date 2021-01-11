#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=210;
const int L = 10010;

int hashTable[N]={0},n,l,m;
int A[L];
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
//    memset(hashTable,-1,sizeof(hashTable));
    for(int i=1;i<=m;i++){
        int color;
        scanf("%d",&color);
        hashTable[color]=i;
    }
    int num=0;
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        int color;
        scanf("%d",&color);
        if(hashTable[color]>0)
            A[num++]=hashTable[color];
    }
    int dp[num],ans=-1;
    for(int i=0;i<num;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(A[j]<=A[i]&&dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }
        ans=max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}

/*LCS解法
与模板不同的是，这个公共序列可以有重复公共元素
            max(dp[i-1][j],dp[i][j-1])+1,A[i]==B[j];
dp[i][j]=
            max(dp[i-1][j],dp[i][j-1]),  A[i]!=B[j]

边界dp[i][0]=dp[0][j]=0;
