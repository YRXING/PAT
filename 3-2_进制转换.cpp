#include<cstdio>

//��P������xת��Ϊʮ������y
int PtoDecimal(int n,int p){
    int product = 1,y=0;
    while(n){
        y+=n%p*product;
        n/=p;
        product*=p;
    }
    return n;
}

int PtoDecimal(int n[],int len,int p){
    int product=1,y=0;
    for(int i=0;i<len;i++){
        y = (y+a[i])*product;
        product*=p;
    }
}


//��ʮ������yת��ΪP������z
/*int z[40],num=0;
do{
    z[num++]=y%P;
    y/=p;
}while(y!=0); //���ʱ��Ӹ�λ���;
*/
