#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=210;
int G[maxn][maxn];
int mp[maxn];
int main(){
    int Nv,Ne;
    memset(G,0,sizeof(G));
    scanf("%d%d",&Nv,&Ne);
    for(int i=0;i<Ne;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u][v]=G[v][u]=1;
    }
    int m,num;
    scanf("%d",&m);
    vector<int> cash;

    for(int i=0;i<m;i++){
        scanf("%d",&num);
        memset(mp,0,sizeof(mp));
        cash.clear();

        int flag=0;
        for(int j=0;j<num;j++){
            int v;
            scanf("%d",&v);
            for(int k=0;k<cash.size();k++){
                if(G[v][cash[k]]!=1){
                    flag=1;
                }
            }
            cash.push_back(v);
            mp[v]++;
        }

        if(flag) printf("Not a Clique\n");

        else{
            flag=0;
            for(int v=1;v<=Nv;v++){
                if(mp[v]==0){
                    int tag=0;
                    for(int j=0;j<cash.size();j++){
                        if(G[v][cash[j]]==0) {tag=1;break;}//不连通，此点不能加到最大的团里
                    }
                    if(tag==0){//这个点和团里面的都联通
                        flag=1;
                        break;
                    }
                }
            }

            if(flag){
                printf("Not Maximal\n");
            }
            else printf("Yes\n");
        }
    }
    return 0;
}
