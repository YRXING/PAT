#include<cstdio>

int main(){
    int k,result[10]={};
//    long long a,b,c,res;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        long long a,b,c,res;
        scanf("%lld%lld%lld",&a,&b,&c);
        res = a+b; //必须存放到long long才可以与C比较
        if(a>0&&b>0&&res<0) result[i]=1;
        else if(a<0&&b<0&&res>=0) result[i]=0;
        else if(res>c) result[i]=1;
        else result[i]=0;
    }
    for(int i=0;i<k;i++){
        if(result[i]) printf("Case #%d: true\n",i+1);
        else printf("Case #%d: false\n",i+1);
    }
    return 0 ;
}
