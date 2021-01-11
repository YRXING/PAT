#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=100010;
const int INF = 1e12;
vector<int> Nodes[maxn];

int n,num=0;
double p,r,ans=INF;

void DFS(int index ,int depth){
    if(Nodes[index].size()==0){
        double price = p*pow(1+r,depth);
        if(price<ans){
            ans = price;
            num=1;  //重置最小深度的个数为1
        }
        else if(price==ans) num++;
        return;
    }
    for(int i=0;i<Nodes[index].size();i++){
        DFS(Nodes[index][i],depth+1);
    }
}

int main(){
    int k,child;
    scanf("%d%lf%lf",&n,&p,&r);
    r/=100;
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        if(k!=0)
            for(int j=0;j<k;j++){
                scanf("%d",&child);
                Nodes[i].push_back(child);
            }
    }

    DFS(0,0);

    printf("%.4lf %d",ans,num);
    return 0;
}
