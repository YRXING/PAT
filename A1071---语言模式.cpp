#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

bool  isCharacter(char c){
    if(c>='0'&&c<='9') return true;
    if(c>='A'&&c<='Z') return true;
    if(c>='a'&&c<='z') return true;
    return false;
}
int main(){
    map<string,int> count;
    string str;
    getline(cin,str);
    int i=0;
    while(i<str.length()){
        string word;
        while(i<str.length()&&isCharacter(str[i])==true){
            if(str[i]>='A'&&str[i]<='Z') str[i]+=32;
            word+=str[i];
            i++;
        }
        if(word!=""){
            if(count.find(word)==count.end()) count[word]=1;
            else count[word]++;
        }
        while(i<str.length()&&isCharacter(str[i])==false)
            i++;
    }
    string ans;
    int MAX=0;
    for(map<string,int>::iterator it=count.begin();it!=count.end();it++){
        if(it->second>MAX) {
            MAX = it->second;
            ans = it->first;
        }
        if(it->second==MAX&&it->first<ans)
            ans=it->first;
    }
    cout<<ans<<" "<<MAX<<endl;
    return 0;
}
//void preDeal(string &str){
//    for(string::iterator it=str.begin();it!=str.end();){
//        if(!isCharacter(*(it))) it=str.erase(it);
//        else ++it;
//    }
//    transform(str.begin(),str.end(),str.begin(),::tolower);
//}
//int main(){
//    string str,temp="{}";
//    map<string,int> MAP;
//    int maxn=-1;
//    while(cin>>str){
//        preDeal(str);
//        if(MAP.find(str)==MAP.end()) MAP[str]=1;
//        else MAP[str]++;
//        if(MAP[str]>maxn){
//            maxn=MAP[str];
//            temp=str;
//        }else if(MAP[str]==maxn&&str<temp){
//            temp=str;
//        }
//        if(getchar()=='\n') break;
//    }
//    cout<<temp<<" "<<MAP[temp];
//
//}
//3号测试点运行超时，不要使用while(cin>>)形式；
