#include<stdio.h>
#include<algorithm>
using namespace std;

const int N = 100010;
int seq[N];

int main(){
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&seq[i]);
    }
    sort(seq,seq+n);
    int i=0,j=0,count = 1;
    while(i<n&&j<n){
        //j��������ֱ��ǡ�ò���������
        while(j<n&&seq[j]<=(long long)seq[i]*p){
            count = max(count,j-i+1);
            j++;
        }
        i++;
    }
    printf("%d",count);
    return 0;
}
//p�������е�Ԫ�ؿ��ܴﵽ10^9���漰�˷���������long long
