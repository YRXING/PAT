/*
1.如果A-B,B-C,那么A-C；
2.已知好朋友信息，可以分为多少组

符合此类题的就是并查集模型
*/
#include<stdio.h>
const int N = 110;
int father[N];//存放父亲结点
bool isRoot[N];//记录每个结点是否作为某个集合的根节点

int findFather(int x){
    int a = x;
    while(x!=father[x]) x = father[x];

    //路径压缩(可不写)
    while(a!=father[a]){
        int z = a;
        father[z] = x;
        a = father[a];
    }
    return x;
}

void  Union(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA!=faB) father[faA] = faB;
}

void init(int n){
    for(int i=1;i<=n;i++) father[i]=i;
    isRoot[i] = false;
}

int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        Union(a,b);
    }
    for(int i=1;i<=n;i++)//遍历n个结点，标记father结点
        isRoot[findFather(i)] = true;
    int ans = 0;//集合数目
    for(int i=1;i<=n;i++) ans+=isRoot[i];
    printf("%d",ans);
    return 0;
}
//如果要进一步求每个集合的数目，把isRoot设置为int型
