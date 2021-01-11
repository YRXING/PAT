#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 1010;
int hobby[N]={0},n,father[N],isRoot[N];

void init(int n){
    for(int i=1;i<=n;i++){
        father[i] = i;
        isRoot[i] = 0;
    }
}

int findFather(int x){
    int a = x;
    while(x!=father[x]) x =father[x];
    while(a!=father[a]){
        int z = a;
        father[z] = x;
        a = father[a];
    }
    return x;
}

void Union(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA!=faB) father[faA] = faB;
}

bool cmp(int a,int b){
    return a>b;
}
int main(){
    scanf("%d",&n);
    init(n);
    int num,h;
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        scanf("%*c%*c");
        for(int j=0;j<num;j++){
            scanf("%d",&h);
            if(hobby[h]==0) hobby[h]=i;
            else Union(i,hobby[h]);
        }
    }

    for(int i=1;i<=n;i++){
        isRoot[findFather(i)]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(isRoot[i]) ans++;
    }
    sort(isRoot+1,isRoot+n+1,cmp);
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++){
        if(i<ans)
            printf("%d ",isRoot[i]);
        else printf("%d",isRoot[i]);
    }
    return 0;
}
