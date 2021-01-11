#include<cstdio>
#include<cmath>

struct Factors{
    int x,cnt;//x质因子，cnt为次数.
}factor[20];

const int maxn=100010;
int Prime[maxn],len=0;
bool p[maxn]={0};

void Find_Prime(){
    for(int i=2;i<maxn;i++){
        if(p[i]==false){
            Prime[len++]=i;
            for(int j=i+i;j<maxn;j+=i)
                p[j]=true;
        }
    }
}

int main(){
    long long n,temp;
    scanf("%lld",&n);
    temp=n;
    if(n==1) {printf("1=1");return 0;}
    Find_Prime();
    long long sqr=(int)sqrt(1.0*n);
    int index=0,faclen=0;
    while(Prime[index++]<=sqr);
    for(int i=0;i<index;i++){
        if(n%Prime[i]==0){
            factor[faclen].x = Prime[i];
            factor[faclen].cnt = 0;
            while(n%Prime[i]==0){
                factor[faclen].cnt++;
                n/=Prime[i];
            }
            faclen++;
        }
    }
    if(n!=1){
        factor[faclen].x=n;
        factor[faclen++].cnt=1;
    }

    printf("%lld=",temp);
    for(int i=0;i<faclen;i++){
        if(i==0){
            if(factor[i].cnt!=1)
                printf("%d^%d",factor[i].x,factor[i].cnt);
            else printf("%d",factor[i].x);
        }
        else{
            if(factor[i].cnt!=1)
                printf("*%d^%d",factor[i].x,factor[i].cnt);
            else printf("*%d",factor[i].x);
        }
    }
    return 0;
}
