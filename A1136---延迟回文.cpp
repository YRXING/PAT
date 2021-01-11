#include<cstdio>
#include<cstring>

struct bign{
    int d[1010];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};

bign change(char str[]){
    int len=strlen(str);
    bign c;
    c.len=len;
    for(int i=0;i<len;i++){
        c.d[len-1-i]=str[i]-'0';
    }
    return c;
}

bign add(bign a,bign b){
    bign c;
    int carry=0;
    for(int i=0;i<a.len||i<b.len;i++){
        int temp=a.d[i]+b.d[i]+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0) c.d[c.len++]=carry;
    return c;
}

bign Reverse(bign a){
    bign c;
    c.len=a.len;
    for(int i=0;i<a.len;i++){
        c.d[i]=a.d[a.len-1-i];
    }
    return c;
}

bool isPalindromic(bign c){
    int len=c.len;
    for(int i=0;i<len/2;i++){
        if(c.d[i]!=c.d[len-1-i]) return false;
    }
    return true;
}

void printBign(bign a){
    for(int i=0;i<a.len;i++){
        printf("%d",a.d[a.len-1-i]);
    }
}

int main(){
    char str[1010];
    scanf("%s",str);
    int n=10;
    bign a=change(str),temp;
    if(isPalindromic(a)){
        printBign(a);
        printf(" is a palindromic number.");
        return 0;
    }
    while(n--){
        temp=Reverse(a);
        printBign(a);
        printf(" + ");
        printBign(temp);
        printf(" = ");
        temp=add(a,temp);
        printBign(temp);
        printf("\n");
        if(isPalindromic(temp)){
            printBign(temp);
            printf(" is a palindromic number.");
            return 0;
        }
        a=temp;
    }
    printf("Not found in 10 iterations.");
    return 0;
}
/*
注意：
测试数据可能直接给出回文数
*/
