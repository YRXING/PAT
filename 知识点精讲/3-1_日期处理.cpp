/*
日期差值，日期连续规定为两天。
输入形式YYYYMMDD
*/


#include<cstdio>
int month[13][2]{{0,0},{31,31},{28,29},{31,31},{30,3},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
//平年28，闰年29
//平年365，闰年366
bool isLeap(int year){
    return (year%4==0&&year%100!=0)||(year%400==0);
}

int differenceValue(int time1,int time2){//time1<=time2
    int y1,y2,m1,m2,d1,d2;
    y1 = time1/10000;m1=time1%10000/100;d1=time1%100;
    y2 = time2/10000;m2=time2%10000/100;d2=time2%100;
    int ans = 1; //记录结果
    while(y1<y2||m1<m2||d1<d2){
        d1++;
        if(d1==month[m1][isLeap(y1)]+1){
            d1=1;
            m1++;
        }
        if(m1==13){m1=1;y1++;}
        ans++;
    }
    return ans;
}

int main(){
    int time1,time2;
    scanf("%d%d",&time1,&time2);
    if(time1>time2){
        int temp = time1;
        time1= time2;
        time2= temp;
    }
    printf("%d",differenceValue(time1,time2));
    return 0;
}
