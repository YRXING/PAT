#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
char str[10001];

int main(){
    scanf("%s",str);
    if(str[0]=='-') printf("-");

    int len=strlen(str);
    int exp,Pos=0;
    while(str[Pos]!='E') Pos++;


    sscanf(str+Pos+2,"%d",&exp);

    if(exp==0){
        for(int i=1;i<Pos;i++) printf("%c",str[i]);
    }

    if(str[Pos+1]!='-'){
        printf("%c",str[1]);
        int i=3;
        while(exp--){
            if(i>=Pos)
                printf("0");
            else printf("%c",str[i]);
            i++;
        }
        if(i<Pos) printf(".");
        for(i;i<Pos;i++) printf("%c",str[i]);
    }else{
        printf("0.");
        exp--;
        while(exp--) printf("0");
        for(int i=1;i<Pos;i++){
            if(str[i]!='.') printf("%c",str[i]);
        }
    }
}
