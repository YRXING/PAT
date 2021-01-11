#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef long long LL;
//radix 下届为所有数位中最大的那个加1，上界为N1进制和下界最大的加1
LL MAP[256];
char n1[20],n2[20],temp[20];

long long inf = (1LL<<63)-1;

void init(){
    for(char c ='0';c<='9';c++) MAP[c] = c-'0';
    for(char c = 'a';c<='z';c++) MAP[c] = c-'a'+10;
}

long long ptodecimal(char a[],long long radix,long long t){
    long long value=0;
    int len = strlen(a);
    for(int i=0;i<len;i++){
        value = value*radix+MAP[a[i]];
        if(value<0||value>t) return -1;
    }
    return value;
}

int cmp(char n2[],long long radix,long long t){
    int len = strlen(n2);
    long long num = ptodecimal(n2,radix,t);//n2转换为10进制
    if(num<0) return 1;//溢出，肯定是N2>t
    if(t>num) return -1;//
    else if(t==num) return 0;
    else return 1;
}

long long binarySearch(char n2[],long long left,long long right,long long t){
    long long mid;
    while(left<=right){
        mid = (left+right)/2;
        int flag = cmp(n2,mid,t);//n2转换为十进制后与t比较；
        if(flag==0) return mid;
        else if(flag==-1) left = mid+1;
        else right = mid -1;

    }
    return -1;
}

int findLargestDigit(char n2[]){
    int ans = -1,len = strlen(n2);
    for(int i=0;i<len;i++){

        if(MAP[n2[i]]>ans) ans = MAP[n2[i]];
    }
    return ans+1;//返回进制的下界
}

int main(){
    int tag,radix;
    init();
    long long value;
    scanf("%s %s %d %d",n1,n2,&tag,&radix);
    if(tag!=1){
        strcpy(temp,n1);
        strcpy(n1,n2);
        strcpy(n2,temp);
    }

    value = ptodecimal(n1,radix,inf);//n1转换为10进制

    long long low = findLargestDigit(n2);//找到n2中数位最大的位下界
    long long high = max(low,value)+1;//上界
    long long ans = binarySearch(n2,low,high,value);
    if(ans==-1)
        printf("Impossible\n");
    else printf("%lld\n",ans);
    return 0;
}

/*
1.使用便利进制暴力枚举会超时
2.转换十进制小于0即溢出
*/
