#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
char str1[80],str2[80],str3[80],str4[80];
char day[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(){
    scanf("%s%s%s%s",str1,str2,str3,str4);
    int len1=strlen(str1);
    int len2=strlen(str2);
    int len3=strlen(str3);
    int len4=strlen(str4);
    int i;
    for(i=0;i<len1&&i<len2;i++){
        if(str1[i]==str2[i]){
            if(str1[i]>='A'&&str1[i]<='G'){
                printf("%s ",day[str1[i]-'A']);
                break;
            }
        }
    }

    for(i++;i<len1&&i<len2;i++){
        if(str1[i]==str2[i]){
            if(str1[i]>='0'&&str1[i]<='9'){
                printf("%02d:",str1[i]-'0');
                break;
            }
            if(str1[i]>='A'&&str1[i]<='N'){
                printf("%02d:",str1[i]-'A'+10);
                break;
            }
        }
    }


    for(i=0;i<len3&&i<len4;i++){
        if(str3[i]==str4[i]&&((str3[i]>='A'&&str3[i]<='Z')||(str3[i]>='a'&&str3[i]<='z')))
        {printf("%02d",i);break;}
    }
    return 0;
}
