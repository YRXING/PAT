#include<cstdio>
#include<map>
using namespace std;
int main(){
    map<int ,bool> mp;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        mp[x]=true;
    }
    int num=1;
    while(mp.find(num)!=mp.end()) num++;
    printf("%d",num);
    return 0;
}
