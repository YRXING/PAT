#include<cstdio>
int main(){

    char id[3]={'W','T','L'},result[3];

    double ans = 1.0,tmp,a;
    int idx;
    for(int i=0;i<3;i++){
        tmp=0.0;
        for(int j=0;j<3;j++){
            scanf("%lf",&a);
            if(a>tmp){tmp=a;idx=j;}
        }
        ans*=tmp;
        result[i]=id[idx];
    }
    printf("%c %c %c %.2f",result[0],result[1],result[2],(ans*0.65-1)*2);
    return 0;
}
