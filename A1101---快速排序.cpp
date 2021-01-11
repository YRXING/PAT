#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace  std;
const int N=100010;
const int INF=1000000000;
int seq[N];
int leftMax[N],rightMin[N];
int main(){
    int n;
    vector<int> select;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&seq[i]);
    leftMax[0]=0;
    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],seq[i-1]);
    }

    rightMin[n-1]=INF;
    for(int i=n-2;i>=0;i--){
        rightMin[i]=min(rightMin[i+1],seq[i+1]);
    }
    for(int i=0;i<n;i++){
        if(seq[i]>leftMax[i]&&seq[i]<rightMin[i]) select.push_back(seq[i]);
    }

    sort(select.begin(),select.end());

    printf("%d\n",select.size());

    for(int i=0;i<select.size();i++){
        printf("%d",select[i]);
        if(i<select.size()-1) printf(" ");
    }
    printf("\n");
    return 0;
}
