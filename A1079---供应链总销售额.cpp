#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=100010;
struct node{
    int level;
    double total_amount;
    vector<int> child;
}Nodes[maxn];

void preOrder(int root){
    if(root==-1) return;
    for(int i=0;i<Nodes[root].child.size();i++){
        int adress = Nodes[root].child[i];
        Nodes[adress].level = Nodes[root].level+1;
        preOrder(adress);
    }
}
int n;
double p,r;
int main(){
    scanf("%d%lf%lf",&n,&p,&r);
    for(int i=0;i<n;i++){
        int tag;
        scanf("%d",&tag);
        if(tag==0){
            double total;
            scanf("%lf",&total);
            Nodes[i].total_amount=total;
            Nodes[i].child.push_back(-1);
        }
        else{
            int child;
            for(int j=0;j<tag;j++){
                scanf("%d",&child);
                Nodes[i].child.push_back(child);
            }
        }
    }
    Nodes[0].level=0;
    preOrder(0);
    double money=0;
    for(int i=0;i<n;i++){
        if(Nodes[i].child[0]==-1)
            money+=Nodes[i].total_amount*pow(1+r/100,Nodes[i].level)*p;
    }
    printf("%.1f",money);
    return 0;
}
