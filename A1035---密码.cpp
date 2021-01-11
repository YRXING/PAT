#include<stdio.h>
#include<string.h>

const int maxn = 1010;
struct Stu{
    char name[20];
    char pwd[20];
    int tag;
    Stu(){
        tag=0;
    }
}stu[maxn];

int main(){
    int n,count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %s",stu[i].name,stu[i].pwd);
        for(int j=0;j<strlen(stu[i].pwd);j++){
            switch(stu[i].pwd[j]){
                case '1':
                    stu[i].pwd[j]='@';
                    stu[i].tag=1;
                    break;
                case '0':
                    stu[i].pwd[j]='%';
                    stu[i].tag=1;
                    break;
                case 'l':
                    stu[i].pwd[j]='L';
                    stu[i].tag=1;
                    break;
                case 'O':
                    stu[i].pwd[j]='o';
                    stu[i].tag=1;
                    break;
            }
        }
        if(stu[i].tag) count++;
    }
    if(!count){//一定要注意题目要求的输出格式
        if(n==1) printf("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified",n);
    }else{
        printf("%d\n",count);
        for(int i=0;i<n;i++){
            if(stu[i].tag) printf("%s %s\n",stu[i].name,stu[i].pwd);
        }
    }
    return 0;
}
