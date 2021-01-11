#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<iostream>
#include<map>
using namespace std;

const int maxn=30010;
struct node{
    string name;
    int Gp,Gm,Gf;
    int G;
}stu[maxn];

int p,m,n,num=0;
map<string,int> nameToID;
int getID(string str){
    if(nameToID.find(str)==nameToID.end()){
        nameToID[str]=num;
        num++;
    }
    return nameToID[str];
}

void init(){
    for(int i=0;i<maxn;i++){
        stu[i].Gf=stu[i].Gm=-1;
        stu[i].G=0;
        stu[i].name="";
    }
}

bool cmp(node a,node b){
    if(a.G!=b.G) return a.G>b.G;
    else return a.name<b.name;
}

int main(){
    init();
    scanf("%d%d%d",&p,&m,&n);
    string str;
    int score;
    for(int i=0;i<p;i++){
        cin>>str>>score;
        if(score>900) continue;
        int id=getID(str);
        stu[id].name=str;
        stu[id].Gp=score;
    }
    for(int i=0;i<m;i++){
        cin>>str>>score;
        if(score>100) continue;
        int id=getID(str);
        stu[id].name=str;
        stu[id].Gm=score;
    }
    for(int i=0;i<n;i++){
        cin>>str>>score;
        if(score>100) continue;
        int id=getID(str);
        stu[id].name=str;
        stu[id].Gf=score;
    }
    for(int i=0;i<num;i++){
        if(stu[i].Gp<200) stu[i].G=-1;
        else{
            if(stu[i].Gm>stu[i].Gf){
                double tt=0.4*stu[i].Gm+0.6*stu[i].Gf;
                if(tt-(int)tt>=0.5) stu[i].G=(int)tt+1;
                else stu[i].G=(int)tt;
            }
            else stu[i].G=stu[i].Gf;
        }
        if(stu[i].G<60) stu[i].G=-1;
    }

    sort(stu,stu+num,cmp);
    for(int i=0;i<num;i++){
        if(stu[i].G!=-1){
            cout<<stu[i].name<<" "<<stu[i].Gp<<" "<<stu[i].Gm<<" "<<stu[i].Gf<<" "<<stu[i].G<<endl;

        }
    }
    return 0;
}

/*
输入的字符串ID反复出现，不能用map或者set排序
1.3号测试点段错误，就要想数组是否开小了，题目说每个不超过10000，所以至少开30000；
2.题目说最大Gp不超过900，Gm和Gf不超过100，因此要加判断
3.向上取整。
*/
