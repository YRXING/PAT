#include<cstdio>

//将P进制数x转换为十进制数y
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


//将十进制数y转换为P进制数z
/*int z[40],num=0;
do{
    z[num++]=y%P;
    y/=p;
}while(y!=0); //输出时候从高位输出;
*/
