#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 2010;
struct Stu{
    int ID;
    int grads[4];
//    int rank[4];
}stulist[maxn];

int Rank[1000000][4]={0};
int now;

bool cmp(Stu a,Stu b){
    return a.grads[now]>b.grads[now];
}

char course[4]={'A','C','M','E'};

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&stulist[i].ID,&stulist[i].grads[1],&stulist[i].grads[2],&stulist[i].grads[3]);
        stulist[i].grads[0] = (int)round((stulist[i].grads[1]+stulist[i].grads[2]+stulist[i].grads[3])/3.0);
    }

    for(now=0;now<4;now++){
        sort(stulist,stulist+n,cmp);
        Rank[stulist[0].ID][now]=1;  //分数最高的设为1
        for(int i=1;i<n;i++){
            if(stulist[i].grads[now]==stulist[i-1].grads[now])
                Rank[stulist[i].ID][now] = Rank[stulist[i-1].ID][now];
            else Rank[stulist[i].ID][now] = i+1;
        }
    }
    int query;
    for(int i=0;i<m;i++){
        scanf("%d",&query);
        if(Rank[query][0]==0) printf("N/A\n");
        else{   //选出rank最小的
            int k=0;
            for(int j=0;j<4;j++){
                if(Rank[query][j]<Rank[query][k]) k=j;
            }
            printf("%d %c\n",Rank[query][k],course[k]);
        }
    }
    return 0;
}
