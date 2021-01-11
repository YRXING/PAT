#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}
int arrayToDigit(int a[]){
    int sum=0;
    for(int i=0;i<4;i++){
        sum = sum*10+a[i];
    }
    return sum;
}
void digitToArray(int *a,int sum){
    for(int i=0;i<4;i++){
        a[i] = sum%10;
        sum/=10;
    }
}

int main(){
    int a[4]={};
    int value;
    scanf("%d",&value);
    digitToArray(a,value);
    int flag=0;
    for(int i=0;i<2;i++){
        if(a[i]!=a[3-i]){
            flag=1;
            break;
        }
    }
    if(!flag) {printf("%04d - %04d = %04d",value,value,0);return 0;}
    int difference=0;
    while(difference!=6174){
        int min,max;
        sort(a,a+4);
        min = arrayToDigit(a);
        sort(a,a+4,cmp);
        max = arrayToDigit(a);
        difference = max - min;
        printf("%04d - %04d = %04d\n",max,min,difference);
        digitToArray(a,difference);
    }

    return 0;
}
