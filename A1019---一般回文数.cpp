#include<stdio.h>

const int maxn=40;
int a[maxn]={};

int main(){
    int n,b,k=0,flag=1;
    scanf("%d%d",&n,&b);
    do{
        a[k++]=n%b;
        n/=b;
    }while(n!=0);
    for(int i=0;i<k/2;i++){
        if(a[i]!=a[k-1-i]){
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    for(int i=k-1;i>0;i--) printf("%d ",a[i]);
    printf("%d",a[0]);
    return 0;
}
