#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=10010;
const int len=13;
struct testee{
    char cardNum[20];
    int score;
}Testees[maxn];

int n,m;
struct result3{
    int place;
    int num;
}result[1000];

bool cmp(testee &a,testee &b){
    if(a.score!=b.score) return a.score>b.score;
    else return strcmp(a.cardNum,b.cardNum)<0;
}

bool cmp3(result3 a,result3 b){
    if(a.num!=b.num) return a.num>b.num;
    else return a.place<b.place;
}
void type1(){
    char c;
    scanf("%*c%c",&c);
    printf("%c\n",c);
    int NA=1;
    for(int i=0;i<n;i++){
        if(Testees[i].cardNum[0]==c) {
            printf("%s %d\n",Testees[i].cardNum,Testees[i].score);
            NA=0;
        }
    }
    if(NA) printf("NA\n");
}

void type2(){
    int place;
    scanf("%d",&place);
    printf("%d\n",place);
    int num=0,sum=0;
    for(int i=0;i<n;i++){
        int p=(Testees[i].cardNum[1]-'0')*100+(Testees[i].cardNum[2]-'0')*10+Testees[i].cardNum[3]-'0';
        if(p==place){
            num++;
            sum+=Testees[i].score;
        }
    }
    if(num==0) printf("NA\n");
    else printf("%d %d\n",num,sum);
}

int strTonum(char str[]){
    int ans=0;
    for(int i=4;i<=9;i++){
        ans=ans*10+str[i]-'0';
    }
    return ans;
}

void type3(){
    int date;
    scanf("%d",&date);
    printf("%06d\n",date);
    int NA=1;
    for(int i=0;i<1000;i++){
        result[i].num=0;
        result[i].place=i;
    }

    for(int i=0;i<n;i++){
        int d=strTonum(Testees[i].cardNum);
        if(d==date) {
            int p=(Testees[i].cardNum[1]-'0')*100+(Testees[i].cardNum[2]-'0')*10+Testees[i].cardNum[3]-'0';
            result[p].num++;
            NA=0;
        }
    }
    sort(result,result+1000,cmp3);
    if(NA) printf("NA\n");
    else{
        for(int i=0;i<1000;i++){
            if(result[i].num){
                printf("%03d %d\n",result[i].place,result[i].num);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s%d",Testees[i].cardNum,&Testees[i].score);
    }
    sort(Testees,Testees+n,cmp);
    int type;
    for(int i=1;i<=m;i++){
        scanf("%d",&type);
        printf("Case %d: %d ",i,type);
        if(type==1) type1();
        else if(type==2) type2();
        else if(type==3) type3();
    }
    return 0;
}
/*
type1:输出指定级别的学生信息，按照socore降序，ID升序
type2:输出指定考场学生数量和总分
type3:输出指定日期的考场，总人数。按照总人数降序，考场升序
排序尽量用引用传参，养成好习惯
*/
