#include<stdio.h>
#include<string.h>


char wei[5][5]={"Shi","Bai","Qian","Wan","Yi"};
char num[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
    char str[15]={'0'};
    scanf("%s",str);
    int len=strlen(str);
    int left=0,right=len-1;

    if(str[0]=='-') {
        printf("Fu");
        left++;
    }

    while(left+4<=right) right-=4;//知道right与left在同一个字节
    while(left<len){//循环处理数字的一节
        bool flag=false;//有无积累的0
        bool isPrint=false;//false 表示该节没有输出过其中的位
        while(left<=right){
            if(left>0&&str[left]=='0') flag=true;
            else{
                if(flag==true){
                    printf(" ling");
                    flag=false;
                }
                if(left>0) printf(" ");//只要不是首位，后面每一位前都要输出空格
                printf("%s",num[str[left]-'0']);
                isPrint=true;
                if(left!=right) printf(" %s",wei[right-left-1]);//除了个位都要输出十百千
            }
            left++;
        }
        if(isPrint&&right!=len-1) printf(" %s",wei[(len-1-right)/4+2]);
        right+=4;
    }
    return 0;
}
