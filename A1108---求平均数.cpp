#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main(){
    int n,cnt=0;
    char a[50],b[50];
    double temp,sum=0.0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s",a);
        sscanf(a,"%lf",&temp);
        sprintf(b,"%.2f",temp);
        int flag=0;
        for(int j=0;j<strlen(a);j++)//扫描出来的和打印出来的一模一样才可以
            if(a[j]!=b[j]) flag=1;

        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }

    if(cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if(cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}

//sscanf(s,"",&b)开头若是非法数字，扫描出来0，尾部非法数字不扫描


//double sum=0;
//int num=0;
//void deal(string str){
//    int flag=1;
//
//    int tag=1;
//    if(str[0]=='-'){
//        str.erase(0,1);//string里面没有erase(value)这个函数!!!!
//        tag=-1;
//    }
//
//    int pos=str.find('.');
//    if(str.length()-1-pos>2) flag=0;
//
//    for(int i=0;i<str.length();i++){
//        if(!(str[i]>='0'&&str[i]<='9')&&i!=pos){flag=0;break;}
//    }
//
//    if(!flag){
//
//        cout<<"ERROR: "<<(tag==1?"":"-")<<str<<" is not a legal number"<<endl;
//        return;
//    }
//    else{
//        double ans=atof(str.c_str());
//        if(ans>1000||ans<-1000) {
//            cout<<"ERROR: "<<(tag==1?"":"-")<<str<<" is not a legal number"<<endl;
//            return;
//        }
//        else{
//            sum+=ans*tag;
//            num++;
//        }
//    }
//}
//
