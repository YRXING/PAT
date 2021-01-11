#include<cstdio>

const int N=10000;
int rank[N]={0};
int hashTable[N]={0};

bool isPrime(int k){
    if(k==1) return false;
    for(int i=2;i*i<=k;i++){//Ò»¶¨ÊÇi*i<=k£¡£¡£¡£¡
        if(k%i==0) return false;
    }
    return true;
}

int main(){
    int n,k,id;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&id);
        rank[id]=i;
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&id);
        printf("%04d: ",id);
        if(hashTable[id]) printf("Checked\n");
        else if(rank[id]==0) printf("Are you kidding?\n");
        else{
            if(rank[id]==1){
                printf("Mystery Award\n");
            }else if(isPrime(rank[id])) printf("Minion\n");
            else printf("Chocolate\n");
            hashTable[id]=1;
        }
    }

    return 0;
}
