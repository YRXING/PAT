#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
map<string,int > image;

int main(){
    int m,n;
    int maxlen=-1;
    string temp,num;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++)
            cin>>num;
            image[num]++;;
            if(image[num]>maxlen){temp = num;maxlen=image[num];}
    }
    cout<<temp;

    return 0;
}
