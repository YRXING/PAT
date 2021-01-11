#include<cstdio>
#include<cstring>

int main(){
    char str[100];
    //gets(str);±¨¸æ±àÒë´íÎó
    scanf("%s",str);
    int N=strlen(str);
    int n1=(N+2)/3,n3=n1,n2=N+2-n1-n3;
    for(int i=0;i<n1-1;i++){
        printf("%c",str[i]);
        for(int j=0;j<n2-2;j++) printf(" ");
        printf("%c\n",str[N-i-1]);
    }
    for(int i=0;i<n2;i++) printf("%c",str[n1+i-1]);
    return 0;
}

//const int max=100;
//char str[max];
//char pic[max][max]={' '};
//int main(){
//    int len=0,row=0,col=0,count=0;;
//    scanf("%s",str);
//    len = strlen(str);
//    row = (len+2)/3;
//    col = (len+2)-row*2;
//    for(int i=0;i<row;i++){
//        pic[i][0]=str[count++];
//    }
//    for(int i=1;i<col;i++) pic[row-1][i]=str[count++];
//    for(int i=row-2;i>=0;i--) pic[i][col-1]=str[count++];
//
//    for(int i=0;i<row;i++){
//        for(int j=0;j<col;j++){
//            printf("%c",pic[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
