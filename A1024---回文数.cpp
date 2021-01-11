#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len = 0;
    }
};

bign change(char str[]){
    bign c;
    int len = strlen(str);
    c.len = len;
    for(int i=0;i<len;i++){
        c.d[len-1-i] = str[i]-'0';
    }
    return c;
}


int is_palin(bign a){
    for(int i=0;i<=a.len/2;i++){
        if(a.d[i]!=a.d[a.len-1-i]) return 0;
    }
    return 1;
}

bign add(bign a, bign b){
    bign c;
    int carry=0;
    for(int i =0;i<a.len||i<b.len;i++){
        c.d[c.len++]=(a.d[i]+b.d[i]+carry)%10;
        carry = (a.d[i]+b.d[i]+carry)/10;
    }
    if(carry) c.d[c.len++]=carry;
    return c;
}

void printBign(bign a){
    for(int i=0;i<a.len;i++){
        printf("%d",a.d[a.len-i-1]);
    }
}
int main(){
     char str[1000];
     int k=0,time;
     scanf("%s %d",str,&time);
     bign a=change(str);
     while(k<time&&!is_palin(a)){
        bign c=a;
        reverse(c.d,c.d+c.len);
        a=add(a,c);
        k++;
     }
    printBign(a);
    printf("\n%d",k);
    return 0;

}

