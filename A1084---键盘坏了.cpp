#include<stdio.h>
#include<cstring>

int hashTable[300]={0};
int main(){
    char origin[100];
    scanf("%s",origin);
    char typedOut[100];
    scanf("%s",typedOut);
    int len1=strlen(origin);
    int len2=strlen(typedOut);
    char c;
    for(int i=0;i<len2;i++){
        c=typedOut[i];
        if(c>='a'&&c<='z') c=c-'a'+'A';
        hashTable[c]=1;
    }
    for(int i=0;i<len1;i++){
        c=origin[i];
        if(c>='a'&&c<='z') c=c-'a'+'A';
        if(!hashTable[c])
            {printf("%c",c);hashTable[c]=1;}
    }
    return 0;
}
