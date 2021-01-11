/*将1-n这n个数围城一个圆环，其中任意两个相邻数字相加，
结果均为素数。第一位固定为1
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100;
bool isPrime[maxn];  //假设都为质数
vector<int> ans;
bool isUsed[maxn];
int n;

void getPrimeTable(){
    memset(isPrime,1,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<maxn;i++){
        if(isPrime[i]){
            for(int j=i+i;j<maxn;j=j+i){
                isPrime[j]=false;
            }
        }
    }
}

void dfs(int index){
    if(index>=n){
        int temp=ans[0]+ans[index-1];  //判断第一个数和最后一个数之和
        if(isPrime[temp]==false){
            return;
        }
        for(int i=0;i<ans.size();i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=2;i<=n;i++){
        if(isUsed[i]==true) continue;
        int temp=ans[index-1]+i;
        if(isPrime[temp]==false) continue;  //剪枝
        //选与不选
        ans.push_back(i);
        isUsed[i]=true;
        dfs(index+1);
        ans.pop_back();
        isUsed[i]=false;
    }
}

int main(){
    getPrimeTable();
    n=6;
    ans.push_back(1);
    dfs(1);
    return 0;
}
