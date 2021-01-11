#include<stdio.h>
#include<string.h>

int main(){
    char N[110];
    int sum=0;
    scanf("%s",N);
    for(int i=0;i<strlen(N);i++){
        sum+=N[i]-'0';
    }
    char english[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int digit[10];
    if(!sum) printf("%s",english[0]);
    else{
        int idx=0;
        while(sum!=0){
            digit[idx++]=sum%10;
            sum/=10;
        }
        for(int i=idx-1;i>0;i--) printf("%s ",english[digit[i]]);
        printf("%s",english[digit[0]]);
    }

    return 0;
}
