#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<set>
using namespace std;
bool sureNoBroken[256];
int main(){
    int k,cnt=1;
    scanf("%d",&k);
    string s;
    cin>>s;
    map<char,bool> m;//出现的健是否坏
    set<char> printed;
    char pre=s[0];
    m[s[0]]=false;

    for(int i=1;i<s.length();i++){
        if(s[i]==pre){
            cnt++;
        }else{
            if(cnt%k!=0) sureNoBroken[pre]=true;
            cnt=1;
        }
        if(cnt%k==0) m[s[i]]=true;
        else m[s[i]]==false;
        pre=s[i];
    }

    for(int i=0;i<s.length();i++){
        if(sureNoBroken[s[i]]==true) m[s[i]]=false;
    }

    for(int i=0;i<s.length();i++){
        if(m[s[i]]&&printed.find(s[i])==printed.end()){
            printf("%c",s[i]);
            printed.insert(s[i]);
        }
    }
    printf("\n");
    for(int i=0;i<s.length();i++){
        printf("%c",s[i]);
        if(m[s[i]]) i=i+k-1;
    }
    return 0;
}
