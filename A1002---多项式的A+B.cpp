#include<cstdio>

const int max_n = 10010;
double COE[max_n] ={};

int main(){
    int k,tag=0,exp;
    double coe;
    scanf("%d",&k);
    while(k--){
        scanf("%d %lf",&exp,&coe);
        COE[exp]+=coe;
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d %lf",&exp,&coe);
        COE[exp]+=coe;
    }
    for(int i=0;i<max_n;i++){
        if(COE[i]) tag++;
    }
    printf("%d",tag);
    for(int i=max_n;i>=0;i--){
        if(COE[i]) printf(" %d %.1f",i,COE[i]);
//        if(!i&&COE[i]) printf("%d %.1f",i,COE[i]);   只有一个零时候输出格式错误
    }
    return 0;
}
