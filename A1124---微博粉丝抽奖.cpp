#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;


int main(){
    int m,n,s;
    scanf("%d%d%d",&m,&n,&s);
    vector<string> List;
    map<string,bool> exite;
    for(int i=1;i<=m;i++){
        string str;
        cin>>str;
        List.push_back(str);
    }
    if(s-1>=List.size()) printf("Keep going...");
    else{
        for(int i=s-1;i<List.size();i+=n){
            while(exite.find(List[i])!=exite.end()) i++;
            cout<<List[i]<<endl;
            exite[List[i]]=true;
        }
    }
    return 0;
}
