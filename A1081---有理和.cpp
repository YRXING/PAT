#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;
struct Fraction{
    LL up,down;
};

LL gcd(LL a,LL b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
Fraction reduction(Fraction result){
    if(result.down<0){
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0){
        result.down = 1;
    }else{
        int d = gcd(abs(result.up),abs(result.down));
        result.up/=d;
        result.down/=d;
    }
    return result;
}

Fraction add(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up*f2.down+f2.up*f1.down;
    result.down = f1.down*f2.down;
    return reduction(result);
}

void showResult(Fraction result){
    result = reduction(result);
    if(result.down==1) printf("%lld\n",result.up);
    else if(abs(result.up)>result.down){
        printf("%lld %lld/%lld",result.up/result.down,abs(result.up)%result.down,result.down);
    }else printf("%lld/%ld",result.up,result.down);
}

int main(){
    int n;
    scanf("%d",&n);
    Fraction sum,value;
    sum.up=0;
    sum.down=1;
    for(int i=0;i<n;i++){
        scanf("%lld/%lld",&value.up,&value.down);
        sum = add(sum,value);
    }
    showResult(sum);
    return 0;
}
