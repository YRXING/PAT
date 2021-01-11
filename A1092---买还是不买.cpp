#include<stdio.h>
#include<ctype.h>
#include<string.h>

int hashFunc(char c){
    if(isdigit(c)) return c-'0';
    if(islower(c)) return c-'a'+10;
    if(isupper(c)) return c-'A'+36;
}

int beads[100]={};

int main(){
    char c[1010];
    int loss=0,extra=0,flag=0;
    scanf("%s",c);
    for(int i=0;i<strlen(c);i++)
        beads[hashFunc(c[i])]++;
    scanf("%s",c);
    for(int i=0;i<strlen(c);i++)
        beads[hashFunc(c[i])]--;

    for(int i=0;i<100;i++){
        if(beads[i]<0){
            flag=1;
            loss-=beads[i];
        }
        extra+=beads[i];
    }
    if(flag) printf("No %d",loss);
    else printf("Yes %d",extra);
    return 0;
}
