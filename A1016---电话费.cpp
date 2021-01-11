#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;


const int N = 1010;
struct Record{
    char name[30];
    int mon,day,hou,minu;
    bool status;  //true ---online false---offline
}rec[N],temp;

int toll[30]; //资费

bool cmp(Record a,Record b){
    int s=strcmp(a.name,b.name);
    if(s!=0) return s<0;
    else if(a.mon!=b.mon) return a.mon<b.mon;
    else if(a.day!=b.day) return a.day<b.day;
    else if(a.hou!=b.hou) return a.hou<b.hou;
    else if(a.minu!=b.minu) return a.minu<b.minu;
}

void get_ans(int on,int off,int &time,int &money){

    temp = rec[on];
    while(temp.day<rec[off].day||temp.hou<rec[off].hou||temp.minu<rec[off].minu){
        time++;
        money+=toll[temp.hou];
        temp.minu++;
        if(temp.minu==60){
            temp.minu=0;
            temp.hou++;
        }
        if(temp.hou==24){
            temp.hou=0;
            temp.day++;
            }

    }
}


int main(){
    int n,time=0,money;
    double total=0;
    for(int i=0;i<24;i++) scanf("%d",&toll[i]);
    scanf("%d",&n);
    char line[10];
    for(int i=0;i<n;i++){
        scanf("%s %d:%d:%d:%d %s",rec[i].name,&rec[i].mon,&rec[i].day,&rec[i].hou,&rec[i].minu,line);
        if(strcmp(line,"on-line")==0) rec[i].status=true;
        else rec[i].status = false;
    }
    sort(rec,rec+n,cmp);

    int needprint=0;
    for(int i=0;i<n-1;i++){
        int s = strcmp(rec[i].name,rec[i+1].name);
        if(s==0&&rec[i].status==true&&rec[i+1].status==false){
            needprint++;
            time=money=0;
            get_ans(i,i+1,time,money);
            if(needprint==1){//新的开始
                printf("%s %02d\n",rec[i].name,rec[i].mon);
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d",rec[i].day,rec[i].hou,rec[i].minu,rec[i+1].day,rec[i+1].hou,rec[i+1].minu);
            printf(" %d $%.2lf\n",time,money/100.0);
            total+=money;
        }
        else if(s!=0&&needprint){
            printf("Total amount: $%.2lf\n",total/100.0);
            total=0;
            needprint=0;
        }
    }

    if(needprint) printf("Total amount: $%.2lf",total/100.0);

    return 0;
}
