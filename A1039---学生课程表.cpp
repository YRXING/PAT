#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int N = 40010;
const int M = 26*26*26*10+1;
vector<int> student[M];
int hashFuc(char str[]){
    int id=0;
    for(int i=0;i<3;i++){
        id = id*26+str[i]-'A';
    }
    return id*10+str[3]-'0';
}

int main(){
    int n,k;
    char name[5];
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        int cnum,snum;
        scanf("%d%d",&cnum,&snum);
        for(int j=0;j<snum;j++){
            scanf("%s",name);
            int id = hashFuc(name);
            student[id].push_back(cnum);
        }
    }
    for(int i=0;i<n;i++){
        scanf("%s",name);
        int id = hashFuc(name);
        sort(student[id].begin(),student[id].end());
        printf("%s %d",name,student[id].size());
        if(student[id].size()!=0)
            for(int j=0;j<student[id].size();j++){
                printf(" %d",student[id][j]);
            }
        printf("\n");
    }
    return 0;
}
/*
1.使用map,string，cin,cout会超时
2.使用二维数组存放学生所选课程编号会导致最后一组数据内存超限，因此使用vector
*/
