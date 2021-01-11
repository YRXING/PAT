#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct student{
    char name[20];
    char id[20];
    int grade;
}stu[maxn];

bool cmp(student a,student b){
    return a.grade>b.grade;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %s %d",stu[i].name,stu[i].id,&stu[i].grade);
    }
    int left,right;
    scanf("%d%d",&left,&right);

    sort(stu,stu+n,cmp);
    int flag=false;
    for(int i=0;i<n;i++){
        if(stu[i].grade>=left&&stu[i].grade<=right){
            printf("%s %s\n",stu[i].name,stu[i].id);
            flag=true;
        }
    }
    if(!flag) printf("NONE");
    return 0;
}
