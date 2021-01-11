#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
int main(){
    int n;
    scanf("%d",&n);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        ans.push_back(x);
    }
    sort(ans.begin(),ans.end());
    int result=0;//未初始化会出错!!!!
    for(int i=n-1;i>=0;i--){
        if(ans[i]>n-i)
            result=n-i;
        else break;
    }
    printf("%d",result);
    return 0;
}
