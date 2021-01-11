#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> statement(n+1,0);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        statement[i]=x;
    }
    int wliar,hliar;
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++){
        wliar=hliar=0;
        for(int k=1;k<=n;k++){
            if(statement[k]<0&&(statement[k]!=-i&&statement[k]!=-j)){
                    if(k==i||k==j) wliar++;
                    else hliar++;
            }
            if(statement[k]>0&&(statement[k]==i||statement[k]==j)){
                    if(k==i||k==j) wliar++;
                    else hliar++;
            }
        }

        if(wliar==1&&hliar==1){
            printf("%d %d",i,j);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
