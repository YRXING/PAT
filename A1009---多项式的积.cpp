#include<cstdio>

const int max_n = 2010;
double COE1[max_n] ={};
double COE3[max_n] = {};

int main(){
    int k,tag=0,exp;
    double coe;
    scanf("%d",&k);
    while(k--){
        scanf("%d %lf",&exp,&coe);
        COE1[exp]+=coe;
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d %lf",&exp,&coe);
        for(int i=0;i<1001;i++){
            COE3[i+exp] +=coe*COE1[i];  //边读边处理，没有必要开三个数组。
        }
    }

    for(int i=0;i<max_n;i++){
        if(COE3[i]) tag++;
    }
    printf("%d",tag);
    for(int i=max_n;i>=0;i--){
        if(COE3[i]) printf(" %d %.1f",i,COE3[i]);
    }
    return 0;
}

