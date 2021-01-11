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
/*����һ������ΪL���ַ�����������е�һ��kλ������
ö��ÿ��kλ���Ӵ�,ת�����������ж��Ƿ���������0,1ҲҪ���ǽ�ȥ��
*/
