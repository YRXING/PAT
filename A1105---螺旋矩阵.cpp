#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=10000;
int matrix[maxn][maxn];
int a[maxn];


bool cmp(int a,int b){
    return a>b;
}
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
        scanf("%d",&a[i]);

    if(num==1){//只有一个元素特判
        printf("%d",a[0]);
        return 0;
    }

    sort(a,a+num,cmp);

    int m=(int)ceil(sqrt(1.0*num));
    while(num%m!=0) m++;
    int n=num/m;

    int x=1,y=1,index=0,L=1,U=1,R=n,D=m;
    while(index<num){
        while(y<R&&index<num){
            matrix[x][y++]=a[index++];}
        while(x<D&&index<num){
            matrix[x++][y]=a[index++];}
        while(y>L&&index<num){
            matrix[x][y--]=a[index++];}
        while(x>U&&index<num){
            matrix[x--][y]=a[index++];}
        L++;U++;R--;D--;
        x++;y++;//位置移动到内层左上角
        if(index==num-1)
            matrix[x][y]=a[index++];
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d",matrix[i][j]);
            if(j<n) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
