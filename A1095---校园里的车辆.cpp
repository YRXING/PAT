#include<stdio.h>
#include<cstring>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

const int N=10010;

struct record{
    char palteNum[10];
    int second;
    char status[5];
}Rec[N],valid[N];

map<string,int> parkTime;
int num=0;
int second(int h,int m,int s){
    return h*3600+m*60+s;
}

bool cmp(record a,record b){
    if(strcmp(a.palteNum,b.palteNum)) return strcmp(a.palteNum,b.palteNum)<0;
    else return a.second<b.second;

}
bool cmpByTime(record a,record b){
    return a.second<b.second;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int h,m,s;
    for(int i=0;i<n;i++){
        scanf("%s %d:%d:%d %s",Rec[i].palteNum,&h,&m,&s,Rec[i].status);
        Rec[i].second=second(h,m,s);
    }
    sort(Rec,Rec+n,cmp);
    int maxTime=-1;

    for(int i=0;i<n-1;i++){
        if(strcmp(Rec[i].palteNum,Rec[i+1].palteNum)==0&&strcmp(Rec[i].status,"in")==0&&strcmp(Rec[i+1].status,"out")==0){
            valid[num++]=Rec[i];
            valid[num++]=Rec[i+1];
            int inTime=Rec[i+1].second-Rec[i].second;
            if(parkTime[Rec[i].palteNum]==0) parkTime[Rec[i].palteNum]=0;
            parkTime[Rec[i].palteNum]+=inTime;
            maxTime=max(maxTime,parkTime[Rec[i].palteNum]);
        }
    }

    sort(valid,valid+num,cmpByTime);

    int nowCar=0,queryTime,index=0;
    for(int i=0;i<k;i++){
        scanf("%d:%d:%d",&h,&m,&s);
        queryTime=second(h,m,s);
        while(index<num&&valid[index].second<=queryTime){
                if(!strcmp(valid[index].status,"in")) nowCar++;
                else nowCar--;
                index++;
        }
        printf("%d\n",nowCar);
    }

    for(map<string,int>::iterator it=parkTime.begin();it!=parkTime.end();it++){
        if(it->second==maxTime) printf("%s ",it->first.c_str());
    }
    printf("%02d:%02d:%02d",maxTime/3600,maxTime%3600/60,maxTime%60);
    return 0;
}
