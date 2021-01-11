#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;
struct people{
    char name[10];
    int age;
    int wealth;
}Richist[maxn],valid[maxn];//所有人在各自年龄中财富值在100名以内的人

int Age[maxn]={0};//某年龄的人数
bool cmp(people a,people b){
    if(a.wealth!=b.wealth) return a.wealth>b.wealth;
    else if(a.age!=b.age) return a.age<b.age;
    else return strcmp(a.name,b.name)<0;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
          scanf("%s%d%d",Richist[i].name,&Richist[i].age,&Richist[i].wealth);
    }
    sort(Richist,Richist+n,cmp);
    int num=0;
    for(int i=0;i<n;i++){
        if(Age[Richist[i].age]<100){
            Age[Richist[i].age]++;
            valid[num++]=Richist[i];//将Richist[i]假如到新的数组
        }
    }
    int m,ageL,ageR;
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&m,&ageL,&ageR);
        printf("Case #%d:\n",i);
        int printNum=0;
        for(int j=0;j<num&&printNum<m;j++){
            if(valid[j].age>=ageL&&valid[j].age<=ageR){
                printf("%s %d %d\n",valid[j].name,valid[j].age,valid[j].wealth);
                printNum++;
            }
        }
        if(!printNum) printf("None\n");
    }
    return 0;
}
