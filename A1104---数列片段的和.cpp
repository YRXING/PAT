#include<cstdio>

int main(){
    int n;
    double sum=0,num;
    scanf("%d",&n);
    for(int i=1,j=n;i<=n;i++,j--){
        scanf("%lf",&num);
        sum+=num*j*i;
    }
    printf("%.2lf",sum);
    return 0;
}
