#include<stdio.h>

int hashTable[10001]={};
int p[100010]={};

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        hashTable[p[i]]++;
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        if(hashTable[p[i]]==1){
            ans=p[i];
            break;
        }
    }
    if(ans==-1) printf("None");
    else printf("%d\n",ans);
    return 0;
}
