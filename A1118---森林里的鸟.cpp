#include<cstdio>
#include<set>
using namespace std;
const int maxn=10010;
int father[maxn];
set<int> total;

void init(){
    for(int i=1;i<maxn;i++){
        father[i]=i;
    }
}

int findFather(int a){
    int x=a;
    while(x!=father[x]) x=father[x];

    while(a!=father[a]){
        int z=a;
        father[z]=x;
        a=father[a];
    }
    return x;
}

void Union(int a,int b){
    int faA=findFather(a);//faA=findFather(a)²»ÊÇfather[a]£¡£¡£¡£¡
    int faB=findFather(b);
    if(faA!=faB) father[faA]=faB;
}

int main(){
    int n;
    init();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k,bird,fa;
        scanf("%d",&k);
        scanf("%d",&fa);
        total.insert(fa);
        for(int i=1;i<k;i++){
            scanf("%d",&bird);
            Union(fa,bird);
            total.insert(bird);
        }
    }

    int ans=0,num=total.size();
    for(int i=1;i<=num;i++){
        if(father[i]==i) ans++;
    }
    printf("%d %d\n",ans,num);

    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(findFather(a)==findFather(b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
