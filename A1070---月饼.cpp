#include<stdio.h>
#include<algorithm>
using namespace std;

const int N=1010;
struct cake{
    double inventory;
    double sell;
    double price;
}C[N];

bool cmp(cake a, cake b){
    return a.price>b.price;
}

int main(){
    int n;
    double m;

    scanf("%d%lf",&n,&m);

    for(int i=0;i<n;i++){
        scanf("%lf",&C[i].inventory);
    }

    for(int i=0;i<n;i++){
        scanf("%lf",&C[i].sell);
        C[i].price=C[i].sell/C[i].inventory;
    }

    sort(C,C+n,cmp);
    int index=0;
    double total=0;
    while(m&&index<n){
        if(C[index].inventory<=m){
            total+=C[index].sell;
            m-=C[index].inventory;
            index++;
        }else{
            total+=C[index].price*m;
            m=0;
        }
    }

    printf("%.2f",total);
    return 0;
}
