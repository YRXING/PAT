//求pow(a,b)%m

/*基于二分思想（也叫二分幂）
快速幂，二进制取幂（Binary Exponentiation，也称平方法），是一个在logn的时间内计算a的n次方的小技巧，而暴力的计算需要o(n)的时间。
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

//快速幂的迭代写法 
/*
b可以表示任意二进制
比如3^13 = 3^(1101) = 3^8*3^4*3^1

*/
LL binaryPow(LL a,LL b,LL m){
    LL ans = 1;
    while(b>0){
        if(b&1) ans = ans*a%m; //如果当前位是1，则乘相应的base
        a = a*a%m; //base翻倍
        b>>=1;//处理下一个位置
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
