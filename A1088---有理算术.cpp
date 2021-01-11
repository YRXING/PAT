#include<cstdio>
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

Fraction minus(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up*f2.down-f2.up*f1.down;
    result.down = f1.down*f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up*f2.up;
    result.down = f1.down*f2.down;
    return reduction(result);
}

Fraction quot(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up*f2.down;
    result.down = f1.down*f2.up;
    return reduction(result);
}

void showResult(Fraction result){
    result = reduction(result);
    if(result.down==1) {
            if(result.up<0)
                printf("(%lld)",result.up);
            else printf("%lld",result.up);
    }
    else if(abs(result.up)>result.down){
        if(result.up<0)
            printf("(%lld %lld/%lld)",result.up/result.down,abs(result.up)%result.down,result.down);
        else printf("%lld %lld/%lld",result.up/result.down,abs(result.up)%result.down,result.down);
        }else{
            if(result.up<0)
                printf("(%lld/%lld)",result.up,result.down);
            else printf("%lld/%lld",result.up,result.down);
        }
}

int main(){
    Fraction a,b;
    scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a,b));
    printf("\n");

    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(minus(a,b));
    printf("\n");

    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(multi(a,b));
    printf("\n");

    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if(b.up==0) printf("Inf");
    else
        showResult(quot(a,b));
    return 0;
}
