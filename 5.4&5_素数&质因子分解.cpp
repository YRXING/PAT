#include<cmath>
//判断素数
bool isPrime(int n){
    if(n<=1) return false;
    int sqr = (int)sqrt(1.0*n);
    for(int i=2;i<=sqr;i++){
        if(n%i==0) return false;
    }
    return true;
}

//素数表的获取
//1.枚举，n<=10`5可以接受；
//筛法:从小到大枚举所有数，对于每一个素数，筛去它所有的倍数，剩下的就是素数了
//使用bool型数组来标记是否被筛掉。
const int maxn=100010;
int prime[maxn],pNum = 0;
bool p[maxn]={0};
void Find_Prime(){
    for(int i=2;i<maxn;i++){
        if(p[i]==false){//i是素数
            prime[pNum++] = i;
            for(int j=i+i;j<maxn;j+=i)
                p[j]=true;
        }
    }
}


//质因子分解 180=2`2*3`2*5`1
struct factor{
    int x,cnt;//x为质因子,cnt为其个数
}fac[10];//对于int型范围的数，数组开到10就够了


//思路：一个数只能被<=sqrt(n)的数整除
//要么就是它本身(这个数为素数)
//1.枚举1-n^1/2所有质因子，判断p是否是n的质因子
if(n%prime[i]==0){
    fac[num].x = prime[i];
    fac[num].cnt = 0;
    while(n%prime[i]==0){
        fac[num].cnt++;
        n/=prime[i];
    }
}
num++;
//2.如果上述步骤结束后n仍然大于1，说明n是素数，有且仅有一个大于sqrt(n)的质因子n
if(n!=1){
    fac[num].x=n;
    fac[num++].cnt=1;
}
