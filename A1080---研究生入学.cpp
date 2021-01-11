#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

struct student{
    int GE,GI,sum;
    int r,stuID;
    int cho[6];
}stu[40010];

struct school{
    int quota;
    int stuNum;//实际招收人数
    int id[40010];//招收学生编号
    int lastAdmit;
}sch[110];

bool cmpStu(student a,student b){
    if(a.sum!=b.sum) return a.sum>b.sum;
    else return a.GE>b.GE;
}

bool cmpID(int a,int b){
    return stu[a].stuID<stu[b].stuID;
}

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d",&sch[i].quota);
        sch[i].stuNum=0;
        sch[i].lastAdmit=-1;
    }

    for(int i=0;i<n;i++){
        stu[i].stuID=i;
        scanf("%d%d",&stu[i].GE,&stu[i].GI);
        stu[i].sum=stu[i].GE+stu[i].GI;
        for(int j=0;j<k;j++){
            scanf("%d",&stu[i].cho[j]);
        }
    }
    sort(stu,stu+n,cmpStu);
    for(int i=0;i<n;i++){//计算排名
        if(i>0&&stu[i].sum==stu[i-1].sum&&stu[i].GE==stu[i-1].GE){
            stu[i].r=stu[i-1].r;
        }else stu[i].r=i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int choice=stu[i].cho[j];
            int num=sch[choice].stuNum;
            int last = sch[choice].lastAdmit;

            if(num<sch[choice].quota||(last!=-1&&stu[i].r==stu[last].r)){
                sch[choice].id[num]=i;
                sch[choice].lastAdmit=i;
                sch[choice].stuNum++;
                break;
            }
        }
    }

    for(int i=0;i<m;i++){
        if(sch[i].stuNum>0){
            sort(sch[i].id,sch[i].id+sch[i].stuNum,cmpID);
            for(int j=0;j<sch[i].stuNum;j++){
                printf("%d",stu[sch[i].id[j]].stuID);
                if(j<sch[i].stuNum-1) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
//const int N=40010;
//const int M=110;
//
//struct student{
//    int id;
//    int GE,GI;
//    int total;
//    int choice[6];
//}stu[N];
//
//struct school{
//    set<int> peple;
//    int last,quota;
//}sch[M];
//
//bool cmp(student a,student b){
//    if(a.total!=b.total) return a.total>b.total;
//    else if(a.GE!=b.GE) return a.GE>b.GE;
//    else return a.id<b.id;
//}
//
//int main(){
//    int n,m,k;
//    scanf("%d%d%d",&n,&m,&k);
//    for(int i=0;i<m;i++){
//        scanf("%d",&sch[i].quota);
//        sch[i].last=-1;
//    }
//
//    for(int i=0;i<n;i++){
//        stu[i].id=i;
//        scanf("%d%d",&stu[i].GE,&stu[i].GI);
//        stu[i].total=stu[i].GE+stu[i].GI;
//        for(int j=0;j<k;j++){
//            scanf("%d",&stu[i].choice[j]);
//        }
//    }
//
//    sort(stu,stu+n,cmp);
//
//    for(int i=0;i<n;i++){
//        int s,last;
//        for(int j=0;j<k;j++){
//            s=stu[i].choice[j];
//            last=sch[s].last;
//            if(sch[s].peple.size()<sch[s].quota){
//                sch[s].peple.insert(stu[i].id);
//                sch[s].last=i;
//                break;
//            }else if(sch[s].peple.size()==sch[s].quota){
//                if(stu[i].total==stu[last].total&&stu[i].GE==stu[last].GE&&last!=-1){
//                    sch[s].peple.insert(stu[i].id);
//                    break;
//                }
//            }else continue;
//        }
//    }
//
//    for(int i=0;i<m;i++){
//        for(set<int>::iterator it=sch[i].peple.begin();it!=sch[i].peple.end();it++){
//            if(it==sch[i].peple.begin())
//                printf("%d",*it);
//            else printf(" %d",*it);
//        }
//        printf("\n");
//    }
//    return 0;
//}
