#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

struct student{
    int ID;
    char name[10];
    int score;
}stu[100010];

int C;

bool cmp(student a, student b){
    if(C==1) return a.ID<b.ID;
    if(C==2){
        int s=strcmp(a.name,b.name);
        if(s!=0)
            return strcmp(a.name,b.name)<0;
        else return a.ID<b.ID;
    }
    if(C==3){
        if(a.score==b.score)
            return a.ID<b.ID;
        else
            return a.score<b.score;
    }
}

int main(){
    int n;
    scanf("%d %d",&n,&C);
    for(int i=0;i<n;i++){
        scanf("%d %s %d",&stu[i].ID,stu[i].name,&stu[i].score);
    }
    sort(stu,stu+n,cmp);
    for(int i=0;i<n;i++)
        printf("%06d %s %d\n",stu[i].ID,stu[i].name,stu[i].score);
    return 0;
}
