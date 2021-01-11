//��n!���ж��ٸ�������p
//1.ֱ�ۼ���1-n�ж��ٸ�������p������ۼ�
int cal(int n,int p){
    int ans = 0;
    for(int i=2;i<=n;i++){
        int temp = i;
        while(temp%p==0){
            ans++;
            temp/=p;
        }
    }
    return ans;
}//n=10^18���޷����ܵ�

/* 2.

                  2
-------------------------
          2       2
-------------------------
      2   2   2   2   2
-------------------------
10!=1*2*3*4*5*6*7*8*9*10

n!����(n/p+n/p^2+n/p^3+...)��������p,��������ȡ����
*/
int cal(int n,int p){
    int ans = 0;
    while(n){
        ans+=n/p;
        n/=p;
    }
    return ans;
}

//��������㷨�����Ժܿ����n!ĩβ�ж��ٸ�0
//n!�ж��ٸ�10=n!���ж��ٸ�5.

//3.n!�������ӵĸ���=n/p�ĸ�������(n/p)!�������ӵĸ���
int cal(int n,int p){
    if(n<p) return 0;
    else return n/p+cal(n/p,p);
}

//������ļ���
//���巨��n<=20
long long C(long long n,long long m){
    long long ans=1;
    for(long long i=1;i<=n;i++)
        ans*=i;
    for(long long i=1;i<=m;i++)
        ans/=i;
    for(long long i=1;i<=n-m;i++)
        ans/=i;
    return ans;
}

//����
long long res[67][67]={0}
long long C(long long n,long long m){
    if(m==0||m==n) return 1;
    if(res[n][m]!=0) return res[n][m];
    return res[n][m] = C(n-1,m)+C(n-1,m-1);
}
//���
const int n = 60;
void calC(){
    fot(int i=0;i<=n;i++)
        res[i][0] = res[i][i] = 1;
    for(int i=2;i<=n;i++)
    for(int j=1;j<=i/2;j++){
        res[i][j] = res[i-1][j]+res[i-1][j-1];
        res[i][i-j] = res[i][j];
    }
}

//ͨ������ı���(n-m+1)*(n-m+2)*...*(n-m+1)/(1*2*...*m)
long long C(long long n,long long m){
    long long ans =1;
    for(long long i=1;i<=m;i++){
            ans = ans*(n-m+i)/i;
    }
    return ans;
}

//%p,���p��������ʹ��lucas����
int Lucas(int n,int m){
    if(m==0) return 1;
    return C(n%p,m%p)*Lucas(n/p,m/p)%p;
}


