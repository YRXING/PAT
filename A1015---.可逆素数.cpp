#include<cstdio>
#include<vector>
using namespace std;

int reverse(int a,int radix){
    vector<int> num;
    while(a!=0){
        num.push_back(a%radix);
        a/=radix;
    }
    int rever=0;
    for(int i=0;i<num.size();i++){
        rever = rever*radix+num[i];
    }
    return rever;
}
const int maxn=100010;
bool p[maxn]={0};

void Find_Prime(){
    p[0]=p[1]=true;
    for(int i=2;i<maxn;i++){
        if(p[i]==false){
            for(int j=2*i;j<maxn;j+=i){
                 p[j]=true;
            }
        }
    }
}

int main(){
    int n,radix;
    Find_Prime();
    while(scanf("%d",&n)&&n>0){
        scanf("%d",&radix);
        if(!p[n]&&!p[reverse(n,radix)]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
