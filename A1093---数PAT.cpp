#include<stdio.h>
#include<cstring>
const int N=100010;
const int prime=1000000007;
char str[N];
int leftP[N]={0};
int rightT[N]={0};
int main(){
    scanf("%s",str);
    int len =strlen(str);
    if(str[0]=='P') leftP[0]=1;
    else leftP[0]=0;
    if(str[len-1]=='T') rightT[len-1]=1;
    else rightT[len-1]=0;

    for(int i=1;i<len;i++){
        if(str[i]=='P') leftP[i]=leftP[i-1]+1;
        else leftP[i]=leftP[i-1];
    }

    int num=0;

    for(int i=len-2;i>=0;i--){
        if(str[i]=='T') rightT[i]=rightT[i+1]+1;
        else if(str[i]=='A') {
            rightT[i]=rightT[i+1];
            num=(num+leftP[i]*rightT[i])%prime;
        }else rightT[i]=rightT[i+1];
    }
    printf("%d",num);
    return 0;
}
