//最大公约数
//辗转相除法gcd(a,b)=gcd(b,a%b)
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

//最小公倍数 lcm(a,b) = a*b/gcd(a,b);
//为避免溢出 a/gcd(a,b)*b;

//分数的四则运算

struct Fraction{
    int up,down;
};

/*
1.down为非负，分数为负，令up为负
2.分数为0，up=0,down=1
3.分子和分母除了1以外没有公约数
*/
Fraction reduction(Fraction result){
    if(result.down<0){
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up = 0){
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
    retult.down = f1.down*f2.down;
    return reduction(result);
}

Fraction minu(Fraction f1,Fraciton f2){
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

Fraction divide(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up*f2.down;
    result.down = f1.down*f2.up;
    return reduction(result);
}//除数不为零

void showResult(Fraction result){
    result = reduction(result);
    if(result.down==1) printf("%lld",result.up);
    else if(abs(result.up)>abs(result.down)){
        printf("%d %d/%d",result.up/result.down,abs(result.up)%result.down,result.down);
    }else printf("%d/%d",result.up,result.down);
}



