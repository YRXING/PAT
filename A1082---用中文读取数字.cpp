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

    while(left+4<=right) right-=4;//֪��right��left��ͬһ���ֽ�
    while(left<len){//ѭ���������ֵ�һ��
        bool flag=false;//���޻��۵�0
        bool isPrint=false;//false ��ʾ�ý�û����������е�λ
        while(left<=right){
            if(left>0&&str[left]=='0') flag=true;
            else{
                if(flag==true){
                    printf(" ling");
                    flag=false;
                }
                if(left>0) printf(" ");//ֻҪ������λ������ÿһλǰ��Ҫ����ո�
                printf("%s",num[str[left]-'0']);
                isPrint=true;
                if(left!=right) printf(" %s",wei[right-left-1]);//���˸�λ��Ҫ���ʮ��ǧ
            }
            left++;
        }
        if(isPrint&&right!=len-1) printf(" %s",wei[(len-1-right)/4+2]);
        right+=4;
    }
    return 0;
}
