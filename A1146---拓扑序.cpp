#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
const int N=1010;
vector<int> G[N],seq,result;
int InDegree[N]={0},num,temp[N];
int n,m;

bool topologicalSort(){
    while(num<n){
        if(temp[seq[num]]!=0) return false;
        for(int i=0;i<G[seq[num]].size();i++){
            int u=G[seq[num]][i];
            temp[u]--;
        }
        num++;
    }
    return true;
}

void copy(){
    for(int i=1;i<=n;i++) temp[i]=InDegree[i];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        InDegree[v]++;
        G[u].push_back(v);
    }

    int k,a,is_first=1;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        seq.clear();
        num=0;
        copy();
        for(int j=0;j<n;j++){
            scanf("%d",&a);
            seq.push_back(a);
        }
        if(!topologicalSort()) result.push_back(i);
    }

    for(int i=0;i<result.size();i++){
        printf("%d",result[i]);
        if(i<result.size()-1) printf(" ");
    }
    return 0;
}
