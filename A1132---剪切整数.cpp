#include<stdio.h>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
int main(){
    int n,z,a,b;
    string str;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>str;
        int len=str.length(),devide=0;
        a=atoi(str.substr(0,len/2).c_str());
        b=atoi(str.substr(len/2,len).c_str());
        z=atoi(str.c_str());
        if(a!=0&&b!=0) devide=z/(a*b);
        if(a*b*devide==z) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
//注意浮点错误，a,b不能是0；
