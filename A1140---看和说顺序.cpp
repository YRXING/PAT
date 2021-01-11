#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin>>s>>n;
    for(int k=1;k<n;k++){
        string t="";
        for(int i=0;i<s.size();i++){
            int cnt=1;
            while(i+1<s.size()&&s[i]==s[i+1]){
                cnt++;
                i++;
            }
            t+=(s.substr(i,1)+to_string(cnt));
        }
        s=t;
    }
    cout<<s;
    return 0;
}
