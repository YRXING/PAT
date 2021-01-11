#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=100010;
struct node{
    double money;
    vector<int> child;
}Nodes[maxn];

int n,root,num=0;
double p,r,higgest=0;
void DFS(int root,int level){
    if(Nodes[root].child.size()==0){
        double money = p*pow(1+r/100,level);
        Nodes[root].money=money;
        if(money>higgest)
            higgest = money;
        return;//加不加都行
    }
    for(int i=0;i<Nodes[root].child.size();i++){
        DFS(Nodes[root].child[i],level+1);
    }
}

int main(){
    scanf("%d%lf%lf",&n,&p,&r);
    for(int i=0;i<n;i++){
        int index;
        scanf("%d",&index);
        if(index==-1) root = i;
        else Nodes[index].child.push_back(i);
    }
    DFS(root,0);
    for(int i=0;i<n;i++){
        if(Nodes[i].money==higgest) num++;
    }
    printf("%.2lf %d",higgest,num);
}

/*此题求出最大深度即可
/void DFS(int index ,int depth){
    if(child[index].size==0){
        if(depth>maxDepth){
            maxnDepth = depth;
            num=1;  //重置最大深度的个数为1
        }
        else if(depth==maxDepth) num++;
    }
    ...
}
*/
