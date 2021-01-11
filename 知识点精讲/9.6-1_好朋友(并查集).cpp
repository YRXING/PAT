/*
1.���A-B,B-C,��ôA-C��
2.��֪��������Ϣ�����Է�Ϊ������

���ϴ�����ľ��ǲ��鼯ģ��
*/
#include<stdio.h>
const int N = 110;
int father[N];//��Ÿ��׽��
bool isRoot[N];//��¼ÿ������Ƿ���Ϊĳ�����ϵĸ��ڵ�

int findFather(int x){
    int a = x;
    while(x!=father[x]) x = father[x];

    //·��ѹ��(�ɲ�д)
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
    for(int i=1;i<=n;i++)//����n����㣬���father���
        isRoot[findFather(i)] = true;
    int ans = 0;//������Ŀ
    for(int i=1;i<=n;i++) ans+=isRoot[i];
    printf("%d",ans);
    return 0;
}
//���Ҫ��һ����ÿ�����ϵ���Ŀ����isRoot����Ϊint��
