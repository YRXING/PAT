#include<stdio.h>
int main(){
    int a,b,index=0,count=0;
    char num[10]={'0'};
    scanf("%d %d",&a,&b);
    a+=b;
    if(a<0) {printf("-");a=-a;}
    if(a==0){printf("0");return 0;}
    while(a){   //Ҳ����ʹ��do...while���� ���Կ���0�������
        num[index++] = a%10+'0';
        count++;
        a/=10;
        if(count%3==0&&a) num[index++] = ',';
    }
    for(int i=index-1;i>=0;i--) printf("%c",num[i]);
    return 0;
}
