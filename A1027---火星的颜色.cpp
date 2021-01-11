#include<stdio.h>

int main(){
    int n;
    char jinzhi[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    char a[6]={'0'};
    for(int i=0;i<3;i++){
        scanf("%d",&n);
        a[i*2]=jinzhi[n/13];
        a[i*2+1]=jinzhi[n%13];
    }
    printf("#");
    for(int i=0;i<6;i++){
        printf("%c",a[i]);
    }
    return 0;
}
