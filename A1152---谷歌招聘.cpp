#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

bool isPrime(int k){
    if(k==0||k==1) return false;
    for(int i=2;i*i<=k;i++){
        if(k%i==0) return false;
    }
    return true;
}

int main(){
    string str;
    int l,k;
    int flag=1;
    cin>>l>>k>>str;
    for(int i=0;i+k-1<l;i++){
        string temp=str.substr(i,k);
        int num=atoi(temp.c_str());
        if(isPrime(num)){
            cout<<temp<<endl;
            flag=0;
            break;
        }
    }
    if(flag) cout<<"404"<<endl;
    return 0;
}
/*给出一个长度为L的字符串，求出其中第一个k位的素数
枚举每个k位的子串,转换成整数，判断是否是素数（0,1也要考虑进去）
*/
