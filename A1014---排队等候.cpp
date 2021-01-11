#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

const int N=21;
const int maxnode=1111;
const int INF=100000000;
struct window{
    int endTime,poptime;
    queue<int> q;
}windows[N];

int minutes(int h,int m){
    return h*60+m;
}

int finish[maxnode],needTime[maxnode];//服务结束时间和服务需要时间

int n,m,k,q,query;

int main(){
    int inIndex=0;
    scanf("%d%d%d%d",&n,&m,&k,&query);
    for(int i=0;i<k;i++){
        scanf("%d",&needTime[i]);
    }
    for(int i=0;i<n;i++) {
        windows[i].endTime=minutes(8,0);
        windows[i].poptime=windows[i].endTime;
    }

    for(int i=0;i<min(n*m,k);i++){//循环入队
        windows[inIndex%n].q.push(inIndex);
        windows[inIndex%n].endTime +=needTime[inIndex];
        if(inIndex<n) windows[inIndex].poptime=needTime[inIndex];
        finish[inIndex]=windows[inIndex%n].endTime;
        inIndex++;
    }

    //处理剩余客户
    for(;inIndex<k;inIndex++){
        //寻找队伍最少的窗口
        int minTime=INF,idx;
        for(int j=0;j<n;j++){
            if(windows[j].poptime<minTime){
                minTime=windows[j].poptime;
                idx=j;
            }
        }

        //引用，下文中用W代替windows[idx]，行文更清晰
        window& W=windows[idx];
        W.q.pop();
        W.q.push(inIndex);
        W.poptime=finish[W.q.front()];
        W.endTime+=needTime[inIndex];
        finish[inIndex]=W.endTime;
    }

    for(int i=0;i<query;i++){
        scanf("%d",&q);
        if(finish[q-1]-needTime[q-1]>=minutes(17,0)){
            printf("Sorry\n");
        }else printf("%02d:%02d\n",finish[q-1]/60,finish[q-1]%60);
    }

    return 0;
}
