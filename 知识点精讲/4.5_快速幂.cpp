//��pow(a,b)%m

/*���ڶ���˼�루Ҳ�ж����ݣ�
1.���b��������pow(a,b) = a*pow(a,b-1);
2.���b��ż����pow(a,b) = pow(a,b/2)*pow(a,b/2);
*/

//�����ݵĵݹ�д��
typedef long long LL;
LL binaryPow(LL a,LL b,LL m){
    if(b==0) return 1;
    if(b&1) return a*binaryPow(a,b-1,m)%m;//  if(b&1)ִ���ٶȿ�һ��
    else{
        LL mul = binaryPow(a,b/2,m);//�������binaryPow(a,b/2)*binaryPow(a,b/2)������������
        return mul*mul%m;
    }
}

/*
1.�����ʼa>m ���뺯��ǰ����a��mȡģ��
2.���m=1��ֱ���ں����ⲿ����Ϊ0��
*/

//�����ݵĵ���д�� a = a`1*a`2*a`4*a`2`k
LL binaryPow(LL a,LL b,LL m){
    LL ans = 1;
    while(b>0){
        if(b&1) ans = ans*a%m;//��ans�ۻ�a
        a = a*a%m;
        b>>=1;
    }


}

//two pointers
//�������Ȿ�������е����ԣ�ʹ�������±�����н���ɨ�裨����ͬ��Ҳ���Է���
//���кϲ�����

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
