#include<cstdio>
#include<vector>
#include<set>
using namespace std;
struct edge{
    int u,v;
};

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<edge> G(m);//边信息
    vector<int> V(n);//点着色信息
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[i].u=u;
        G[i].v=v;
    }

    int k,p_color;
    set<int> color;//颜色数量
    scanf("%d",&k);

    for(int i=0;i<k;i++){
        color.clear();
        for(int j=0;j<n;j++){
            scanf("%d",&p_color);
            color.insert(p_color);
            V[j]=p_color;
        }

        int flag=1;
        for(int j=0;j<m;j++){
            if(V[G[j].u]==V[G[j].v]){flag=0;break;}
        }

        if(flag) printf("%d-coloring\n",color.size());
        else printf("No\n");
    }
    return 0;
}
