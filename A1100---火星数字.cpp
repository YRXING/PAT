#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
string unitDigit[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string,int> MTE;
string ETM[170];
void init(){
    for(int i=0;i<13;i++){
        ETM[i] = unitDigit[i];//个位为[0,12],十位为0
        MTE[unitDigit[i]]=i;
        ETM[i*13] = tenDigit[i];//十位为[0,12]，个位为0
        MTE[tenDigit[i]] = i*13;
    }
    for(int i=1;i<13;i++){
        for(int j=1;j<13;j++){
            string str = tenDigit[i]+" "+unitDigit[j];
            MTE[str] = i*13+j;
            ETM[i*13+j]=str;
        }
    }
}
int main(){
    init();
    int n;
    scanf("%d%*c",&n);
    for(int i=0;i<n;i++){
        string str;
        getline(cin,str);
        if(str[0]>='0'&&str[0]<='9'){
            int num=0;
            for(int i=0;i<str.length();i++)
                num = num*10+(str[i]-'0');
            cout<<ETM[num]<<endl;
        }else{
            cout<<MTE[str]<<endl;
        }
    }

    return 0;
}
/*
1.规模小，直接打表*/
