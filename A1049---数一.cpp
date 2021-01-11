#include<stdio.h>

int main(){
    int a=1,n,ans=0;
    int left,now,right;
    scanf("%d",&n);
    while(n/a){
        left=n/(a*10);
        right=n%a;
        now=n%(a*10)/a;
        if(now==0){
            ans+=left*a;
        }else if(now==1){
            ans+=left*a+right+1;
        }else ans+=(left+1)*a;
        a*=10;
    }
    printf("%d",ans);
    return 0;
}
