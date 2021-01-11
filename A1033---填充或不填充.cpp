#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;
struct gastation{
    double price;
    double distance;
    gastation(){
        price=0;
        distance=0;
    }
}gast[maxn];

bool cmp(gastation a, gastation b){
    return a.distance<b.distance;
}
double maxdist,C,D,Davg;
int N;
int flag;//1表示下一站price比本站少，0表示下一站是左右能到达的最小的价格。
double money;//累积的钱
double dist=0;//行驶的距离
int  next_station(int now_station){
    int next_sta=now_station+1;
    int k=-1;//----------------
    double minprice=INF;
    while(next_sta<=N&&(gast[next_sta].distance-gast[now_station].distance)<=maxdist){
        if(gast[next_sta].price<gast[now_station].price){
            flag = 1;
            k = next_sta;
            return k;
        }
        else if(gast[next_sta].price<minprice){
                minprice = gast[next_sta].price;
                k = next_sta;
        }
        next_sta++;
    }
    flag = 0;
    return k;
}
int main(){
    scanf("%lf%lf%lf%d",&C,&D,&Davg,&N);
    for(int i=0;i<N;i++){
        scanf("%lf %lf",&gast[i].price,&gast[i].distance);
    }
    gast[N].distance = D; //终点站
    sort(gast,gast+N,cmp);
    if(gast[0].distance!=0){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    maxdist = C*Davg;
    int now_station=0,next_sta;
    double need_gas,tank=0;
    while(now_station<N){
        next_sta = next_station(now_station);
        if(next_sta ==-1) break; //满油状态下无法找到加油站
        need_gas = (gast[next_sta].distance-gast[now_station].distance)/Davg;
        if(flag){
            if(need_gas>tank){//--------------------
                money+=(need_gas-tank)*gast[now_station].price;
                tank = 0;
            }
            else tank -=need_gas;
        }else {
            money+=(C-tank)*gast[now_station].price;
            tank = C-need_gas;
        }
         now_station = next_sta;
    }
    if(now_station==N) printf("%.2f\n",money);
    else printf("The maximum travel distance = %.2f\n",gast[now_station].distance+maxdist);

    return 0;
}
