#include<cstdio>

const int Max = 100;

int seconds(int h,int m,int s){
    return s+m*60+h*3600;
}
int main(){
    int h,m,s,k,eid=0,lid=0;
    int etimes=100000,ltimes=-100000;
    char id[Max][15];

    scanf("%d",&k);
    for(int i =0;i<k;i++){
        scanf("%s",id[i]);
        scanf("%d:%d:%d",&h,&m,&s);
        if(seconds(h,m,s)<etimes){
            eid = i;
            etimes = seconds(h,m,s);
        }
        scanf("%d:%d:%d",&h,&m,&s);
        if(seconds(h,m,s)>ltimes){
            lid = i;
            ltimes = seconds(h,m,s);
        }
    }
    printf("%s %s",id[eid],id[lid]);
    return 0;
}
