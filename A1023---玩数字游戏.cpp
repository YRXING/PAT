#include<stdio.h>
#include<string.h>

using namespace std;

struct bign{
    int d[30];
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

bign Double(bign a){
    bign c;
    int carry=0;
    for(int i=0;i<a.len;i++){
        c.d[c.len++] = (a.d[i]*2+carry)%10;
        carry = (a.d[i]*2+carry)/10;
    }
    while(carry) {
        c.d[c.len++] = carry%10;
        carry/=10;
    }
    return c;
}

int has_property(bign a){
    int hashTable[10]={0};
    bign c = Double(a);
    if(a.len!=c.len) return 0;
    for(int i=0;i<c.len;i++){
        hashTable[c.d[i]]++;
        hashTable[a.d[i]]--;
    }
    for(int i=0;i<10;i++){
        if(hashTable[i]!=0) return 0;
    }

    return 1;
}

void printBign(bign a){
    for(int i=a.len-1;i>=0;i--){
        printf("%d",a.d[i]);
    }
}

int main(){
    char str[30];
    scanf("%s",str);
    bign a = change(str);
    if(has_property(a))
        printf("Yes\n");
    else printf("No\n");
    printBign(Double(a));
    return 0;

}
