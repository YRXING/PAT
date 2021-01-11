#include<cstdio>
#include<cmath>
typedef long long LL;

int main(){
    int n;
    scanf("%d",&n);
    int sqr = (int)sqrt(1.0*n);
    int ansi,anslen=0;
    for(int i=2;i<=sqr;i++){
        int len=0;
        LL num=1;
        for(int j=i;j<=sqr;j++){
            num*=j;
            if(n%num==0) {
                len++;
            }
            else break;
        }
        if(len>anslen) {ansi=i;anslen=len;}
    }
    if(anslen==0) printf("1\n%d",n);
    else {
        printf("%d\n",anslen);
        for(int i=0;i<anslen;i++){
            if(i==0) {printf("%d",ansi++);}
            else printf("*%d",ansi++);
        }
    }
    return 0;
}
