//求n!中有多少个质因子p
//1.直观计算1-n有多少个质因子p，结果累加
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
}//n=10^18是无法承受的

/* 2.

                  2
-------------------------
          2       2
-------------------------
      2   2   2   2   2
-------------------------
10!=1*2*3*4*5*6*7*8*9*10

n!中有(n/p+n/p^2+n/p^3+...)个质因子p,除法向下取整。
*/
int cal(int n,int p){
    int ans = 0;
    while(n){
        ans+=n/p;
        n/=p;
    }
    return ans;
}

//利用这个算法，可以很快计算n!末尾有多少个0
//n!有多少个10=n!中有多少个5.

//3.n!中质因子的个数=n/p的个数加上(n/p)!中质因子的个数
int cal(int n,int p){
    if(n<p) return 0;
    else return n/p+cal(n/p,p);
}

//组合数的计算
//定义法，n<=20
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

//递推
long long res[67][67]={0}
long long C(long long n,long long m){
    if(m==0||m==n) return 1;
    if(res[n][m]!=0) return res[n][m];
    return res[n][m] = C(n-1,m)+C(n-1,m-1);
}
//打表
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

//通过定义的变形(n-m+1)*(n-m+2)*...*(n-m+1)/(1*2*...*m)
long long C(long long n,long long m){
    long long ans =1;
    for(long long i=1;i<=m;i++){
            ans = ans*(n-m+i)/i;
    }
    return ans;
}

//%p,如果p是素数，使用lucas定理
int Lucas(int n,int m){
    if(m==0) return 1;
    return C(n%p,m%p)*Lucas(n/p,m/p)%p;
}


