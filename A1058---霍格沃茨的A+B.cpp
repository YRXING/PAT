#include<stdio.h>

int main(){
    int g1,s1,k1,g2,s2,k2,g3,s3,k3;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    int carry = 0;
    k3=(k1+k2)%29;
    carry=(k1+k2) /29;
    s3 = (s1+s2+carry)%17;
    carry = (s1+s2+carry)/17;
    g3 = g1+g2+carry;
    printf("%d.%d.%d",g3,s3,k3);

    return 0;
}
