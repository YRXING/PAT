//求pow(a,b)%m

/*基于二分思想（也叫二分幂）
1.如果b是奇数，pow(a,b) = a*pow(a,b-1);
2.如果b是偶数，pow(a,b) = pow(a,b/2)*pow(a,b/2);
*/

//快速幂的递归写法
typedef long long LL;
LL binaryPow(LL a,LL b,LL m){
    if(b==0) return 1;
    if(b&1) return a*binaryPow(a,b-1,m)%m;//  if(b&1)执行速度快一点
    else{
        LL mul = binaryPow(a,b/2,m);//如果返回binaryPow(a,b/2)*binaryPow(a,b/2)计算量会增大
        return mul*mul%m;
    }
}

/*
1.如果初始a>m 进入函数前就让a对m取模。
2.如果m=1，直接在函数外部特判为0。
*/

//快速幂的迭代写法 a = a`1*a`2*a`4*a`2`k
LL binaryPow(LL a,LL b,LL m){
    LL ans = 1;
    while(b>0){
        if(b&1) ans = ans*a%m;//领ans累积a
        a = a*a%m;
        b>>=1;
    }


}

//two pointers
//利用问题本身与序列的特性，使用两个下标对序列进行扫描（可以同向，也可以反向）
//序列合并问题

int merge(int A[],int B[],int C[],int n,int m){
    int i=0,j=0,index = 0;
    while(i<n&&j<m){
        if(A[i]<=B[i]) C[index++] = A[i++];
        else C[index++] = B[j++];
    }
    while(i<n) C[index++] = A[i++];
    while(j<m) C[index++] = B[j++];
    return index;
}
