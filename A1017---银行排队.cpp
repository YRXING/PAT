#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

const int N=10010;
const int K=110;
struct node{
    int arrive;
    int serve;
};

vector<node> customer;//模拟队列
int endTime[K],n,k;
int open,close,totalWaite=0;
int second(int h,int m,int s){
    return h*3600+m*60+s;
}

bool cmp(node a,node b){
    return a.arrive<b.arrive;
}

void serve(node &a){
    int minEndTime=1000000,window=-1;
    for(int i=0;i<k;i++){//选择最早结束窗口
        if(endTime[i]<minEndTime){
            minEndTime=endTime[i];
            window=i;
        }
    }

    if(endTime[window]<=a.arrive){
        endTime[window]=a.arrive+a.serve;
    }else{
        totalWaite+=endTime[window]-a.arrive;
        endTime[window]+=a.serve;
    }
}

int main(){
    int h,m,s,ser;
    open=second(8,0,0);//开门时间
    close = second(17,0,0);//关门时间
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){//初始化
        endTime[i]=open;
    }
    node c;
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d %d",&h,&m,&s,&ser);
        int comeTime=second(h,m,s);
        if(comeTime>close)  continue;
        c.arrive=comeTime;
        c.serve=ser<=60?ser*60:3600;
        customer.push_back(c);
    }

    sort(customer.begin(),customer.end(),cmp);

    for(int i=0;i<customer.size();i++){
        serve(customer[i]);
    }

    if(customer.size()==0) printf("0.0");
    else printf("%.1f",totalWaite/60.0/customer.size());
    return 0;
}
