#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

struct Testee{
    char ID[20];
    int score;
    int lnumber,lrank;
}testee[30010];

bool cmp(Testee a,Testee b){
    if(a.score!=b.score) return a.score>b.score;
    else return strcmp(a.ID,b.ID)<0;
}

int main(){
    int n,k,total=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%s %d",testee[total].ID,&testee[total].score);//易错
            testee[total].lnumber=i;
            total++;
        }
        sort(testee+total-k,testee+total,cmp);
        testee[total-k].lrank=1; //第一个设置为1;
        for(int j=total-k+1;j<total;j++){
            if(testee[j].score==testee[j-1].score) testee[j].lrank=testee[j-1].lrank;
            else testee[j].lrank=j+1-(total-k);
        }
    }
    sort(testee,testee+total,cmp);
    int r=1;
    printf("%d\n",total);
    for(int j=0;j<total;j++){
        if(j>0&&testee[j].score!=testee[j-1].score) r=j+1;
        printf("%s %d %d %d\n",testee[j].ID,r,testee[j].lnumber,testee[j].lrank);
    }
    return 0;
}
