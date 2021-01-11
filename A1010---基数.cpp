#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef long long LL;
//radix �½�Ϊ������λ�������Ǹ���1���Ͻ�ΪN1���ƺ��½����ļ�1
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
    long long num = ptodecimal(n2,radix,t);//n2ת��Ϊ10����
    if(num<0) return 1;//������϶���N2>t
    if(t>num) return -1;//
    else if(t==num) return 0;
    else return 1;
}

long long binarySearch(char n2[],long long left,long long right,long long t){
    long long mid;
    while(left<=right){
        mid = (left+right)/2;
        int flag = cmp(n2,mid,t);//n2ת��Ϊʮ���ƺ���t�Ƚϣ�
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
    return ans+1;//���ؽ��Ƶ��½�
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

    value = ptodecimal(n1,radix,inf);//n1ת��Ϊ10����

    long long low = findLargestDigit(n2);//�ҵ�n2����λ����λ�½�
    long long high = max(low,value)+1;//�Ͻ�
    long long ans = binarySearch(n2,low,high,value);
    if(ans==-1)
        printf("Impossible\n");
    else printf("%lld\n",ans);
    return 0;
}

/*
1.ʹ�ñ������Ʊ���ö�ٻᳬʱ
2.ת��ʮ����С��0�����
*/
