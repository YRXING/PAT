#include<cmath>
//�ж�����
bool isPrime(int n){
    if(n<=1) return false;
    int sqr = (int)sqrt(1.0*n);
    for(int i=2;i<=sqr;i++){
        if(n%i==0) return false;
    }
    return true;
}

//������Ļ�ȡ
//1.ö�٣�n<=10`5���Խ��ܣ�
//ɸ��:��С����ö��������������ÿһ��������ɸȥ�����еı�����ʣ�µľ���������
//ʹ��bool������������Ƿ�ɸ����
const int maxn=100010;
int prime[maxn],pNum = 0;
bool p[maxn]={0};
void Find_Prime(){
    for(int i=2;i<maxn;i++){
        if(p[i]==false){//i������
            prime[pNum++] = i;
            for(int j=i+i;j<maxn;j+=i)
                p[j]=true;
        }
    }
}


//�����ӷֽ� 180=2`2*3`2*5`1
struct factor{
    int x,cnt;//xΪ������,cntΪ�����
}fac[10];//����int�ͷ�Χ���������鿪��10�͹���


//˼·��һ����ֻ�ܱ�<=sqrt(n)��������
//Ҫô����������(�����Ϊ����)
//1.ö��1-n^1/2���������ӣ��ж�p�Ƿ���n��������
if(n%prime[i]==0){
    fac[num].x = prime[i];
    fac[num].cnt = 0;
    while(n%prime[i]==0){
        fac[num].cnt++;
        n/=prime[i];
    }
}
num++;
//2.����������������n��Ȼ����1��˵��n�����������ҽ���һ������sqrt(n)��������n
if(n!=1){
    fac[num].x=n;
    fac[num++].cnt=1;
}
