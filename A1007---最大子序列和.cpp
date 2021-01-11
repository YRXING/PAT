#include<stdio.h>
#include<algorithm>
using namespace std;
const int K = 10010;
int A[K],dp[K],s[K]={0};//dp[i]的连续序列从哪一项开始
int n;
bool isNegative(){
    for(int i=0;i<n;i++){
        if(A[i]>=0) return false;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    if(isNegative()){
        printf("0 %d %d",A[0],A[n-1]);
        return 0;
    }

    dp[0]=A[0];
//    int ans=-1,k;
    for(int i=1;i<n;i++){
        if(dp[i-1]+A[i]>A[i]){
            dp[i]=dp[i-1]+A[i];
            s[i]=s[i-1];
        }else{
            dp[i]=A[i];
            s[i]=i;
        }
//        if(dp[i]>ans) {ans=dp[i];k=i;}
    }
    int k=0;
    for(int i=1;i<n;i++){
        if(dp[i]>dp[k]){
            k=i;
        }
    }
    printf("%d %d %d",dp[k],A[s[k]],A[k]);
    return 0;
}
