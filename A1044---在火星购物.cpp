#include<stdio.h>

const int N = 100010;
long long sum[N]={};

int lower_bound(int left,int right,int x){
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(sum[mid]>=x) right = mid;
        else left = mid+1;
    }
    return left;
}


int main(){
    int n,m,value;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&value);
        sum[i] = sum[i-1]+value;
    }
    int nearS=100000001;
    for(int i=1;i<=n;i++){
        int index = lower_bound(i,n,sum[i-1]+m);
        if(sum[index]-sum[i-1]==m) {nearS = m;break;}
        else if(sum[index]-sum[i-1]<nearS&&sum[index]-sum[i-1]>m) nearS = sum[index]-sum[i-1];
    }


    for(int i=1;i<=n;i++){
        int index = lower_bound(i,n,sum[i-1]+m);
        if(sum[index]-sum[i-1]==nearS)
            printf("%d-%d\n",i,index);
    }
    return 0;
}
