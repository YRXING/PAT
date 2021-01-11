#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1010;
int a[N];
//bool juge(int n){
//    for(int i=1;i<=n;i++)
//    for(int j=i+1;j<=n;j++){
//        if(abs(i-j)==abs(a[i]-a[j])) return false;
//    }
//    return true;
//}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int len;
        bool result=true;
        scanf("%d",&len);
        for(int j=1;j<=len;j++){
            scanf("%d",&a[j]);
            for(int t=1;t<j;t++){
                if(abs(j-t)==abs(a[j]-a[t])||a[j]==a[t]){
                    result=false;
                    break;
                }
            }
        }
        if(result) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
