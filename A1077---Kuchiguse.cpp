#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

void Reverse(char *str,int n){
    char temp;
    for(int i=0;i<n/2;i++){
        temp = *(str+i);
        *(str+i) = *(str+n-1-i);
        *(str+n-1-i) = temp;
    }

}

int main(){
    char spoken[110][300];
    int n ,idx=0,minlen=-1;
    scanf("%d",&n);
    getchar();//      ½ÓÊÕ»»ÐÐ·û
    for(int i=0;i<n;i++){
        cin.getline(spoken[i],300);
        if(strlen(spoken[i])<minlen) minlen = strlen(spoken[i]);
        Reverse(spoken[i],strlen(spoken[i]));
    }

    for(int i=0;i<minlen;i++){
        int flag = 1;
        for(int j=1;j<n;j++){
            if(spoken[j][i]!=spoken[0][i]){
                flag=0;
                break;
            }
        }
        if(flag) idx++;
        else break;
    }
    if(idx==0) printf("nai");
    else {
        for(int i=idx-1;i>=0;i--){
            printf("%c",spoken[0][i]);
        }
    }
    return 0;
}
