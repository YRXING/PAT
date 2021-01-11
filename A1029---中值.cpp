#include<cstdio>
const int N = 200010;
int s[N];
const int INF = 0x7fffffff;
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    scanf("%d",&m);
    s[n+1]=INF;
    int median = (n+m+1)/2;
    int i=1,count=0;
    int temp;
    for(int j=1;j<=m;j++){
        scanf("%d",&temp);
        while(s[i]<temp){
            count++;
            if(count==median) printf("%d",s[i]);
            i++;
        }
        count++;
        if(count==median) printf("%d",temp);
    }
    while(i<=n&&count!=median){
        count++;
        if(count==median) printf("%d",s[i]);
        i++;
    }
    return 0;
}
