#include<stdio.h>
#include<string.h>

const int maxn=10010;
char s1[maxn],s2[maxn];

int hashTable[300]={};
int main(){
    fgets(s1,maxn,stdin);
    fgets(s2,maxn,stdin);
    for(int i=0;i<strlen(s2);i++){
        hashTable[s2[i]]=1;
    }
    for(int i=0;i<strlen(s1);i++){
        if(!hashTable[s1[i]]) printf("%c",s1[i]);
    }
    return 0;
}

