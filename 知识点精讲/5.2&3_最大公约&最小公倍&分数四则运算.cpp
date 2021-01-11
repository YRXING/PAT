//���Լ��
//շת�����gcd(a,b)=gcd(b,a%b)
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

//��С������ lcm(a,b) = a*b/gcd(a,b);
//Ϊ������� a/gcd(a,b)*b;

//��������������

struct Fraction{
    int up,down;
};

/*
1.downΪ�Ǹ�������Ϊ������upΪ��
2.����Ϊ0��up=0,down=1
3.���Ӻͷ�ĸ����1����û�й�Լ��
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
}//������Ϊ��

void showResult(Fraction result){
    result = reduction(result);
    if(result.down==1) printf("%lld",result.up);
    else if(abs(result.up)>abs(result.down)){
        printf("%d %d/%d",result.up/result.down,abs(result.up)%result.down,result.down);
    }else printf("%d/%d",result.up,result.down);
}



