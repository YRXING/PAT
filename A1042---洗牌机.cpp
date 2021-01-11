#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int main(){
    char mp[5]={'S','H','C','D','J'}; //mp[(x-1)/13]为花色，(x-1)%13+1为编号。
    int k,temp;
    int permu[55]={},Start[55]={},result[55]={};

    scanf("%d",&k);
    for(int i=1;i<=54;i++){
        scanf("%d",&permu[i]);
        Start[i]=i;
    }
    while(k--){
        for(int i=1;i<=54;i++){
            result[permu[i]] = Start[i];
        }
        for(int i=1;i<=54;i++){
            Start[i] = result[i];
        }
    }

    for(int i=1;i<=54;i++){
        if(i!=54) {
            printf("%c%d ",mp[(result[i]-1)/13], (result[i]-1)%13+1);
        }
        else printf("%c%d",mp[(result[i]-1)/13], (result[i]-1)%13+1);
    }
    return 0 ;
}
