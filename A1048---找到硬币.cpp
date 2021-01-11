#include<stdio.h>
#include<algorithm>
using namespace std;

const int N=100010;
int a[N]={};

//tow pointers
int main(){
    int n,m,sum,flag=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int Start=0,End=n-1;
    while(Start<End){
        sum = a[Start]+a[End];
        if(sum==m){
            printf("%d %d",a[Start],a[End]);
            flag=1;
            break;
        }
        else if(sum>m) End--;
        else Start++;
    }
    if(!flag) printf("No Solution");
    return 0;
}

/*hashTable
const int N = 1005;
int HashTable[N]=0;
int main(){
    int n,m,a;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        HashTable[a]++;
    }
    for(int i=0;i<N;i++){
        if(HashTable[i]&&HashTable[m-i]){
            if(i==m-i&&hashTable[i]<=1)
                continue;
            printf("%d %d\n",i,m-i);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}
*/
