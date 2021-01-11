#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1010;
char str[N];
int dp[N][N];
int main(){
    cin.getline(str,N);
    int len = strlen(str);
    fill(dp[0],dp[0]+N*N,0);
    int ans=1;
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        if(i<len-1&&str[i]==str[i+1]){
            dp[i][i+1]=1;
            ans=2;
        }
    }

    for(int L=3;L<=len;L++){
        for(int i=0;i+L-1<len;i++){
            int j=i+L-1;
            if(str[i]==str[j]&&dp[i+1][j-1]==1){
                dp[i][j]=1;
                ans=L;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
