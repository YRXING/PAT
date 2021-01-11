#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010;

struct people{
    int id;
    int v,t,total;
    int flag;
}p[N];

int num=0;
int n,l,h;
bool cmp(people a,people b){
    if(a.flag!=b.flag) return a.flag<b.flag;
    else if(a.total!=b.total) return a.total>b.total;
    else if(a.v!=b.v) return a.v>b.v;
    else return a.id<b.id;
}

int main(){
    scanf("%d%d%d",&n,&l,&h);
    for(int i=0;i<n;i++){
        int id,v,t;
        scanf("%d%d%d",&id,&v,&t);
        if(v>=l&&t>=l){
            p[num].id=id;
            p[num].v=v;
            p[num].t=t;
            p[num].total=v+t;
            if(v>=h&&t>=h) p[num].flag=1;
            else if(v>=h&&t<h) p[num].flag=2;
            else if(v>=t)
                 p[num].flag=3;
            else p[num].flag=4;
            num++;
        }
    }
    sort(p,p+num,cmp);
    printf("%d\n",num);
    for(int i=0;i<num;i++){
        printf("%08d %d %d\n",p[i].id,p[i].v,p[i].t);
    }
    return 0;
}
