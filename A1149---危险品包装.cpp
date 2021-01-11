#include<cstdio>
#include<set>
#include<vector>
using namespace std;
const int maxn=100000;
vector<int> Pair[maxn];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    set<int> pakage;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Pair[a].push_back(b);
        Pair[b].push_back(a);
    }

    for(int i=0;i<k;i++){
        int num;
        scanf("%d",&num);
        pakage.clear();
        for(int j=0;j<num;j++){
            int goods;
            scanf("%d",&goods);
            pakage.insert(goods);
        }

        int flag=1;
        for(set<int>::iterator it=pakage.begin();it!=pakage.end();it++){
            if(Pair[*it].size()!=0){
                for(int j=0;j<Pair[*it].size();j++){
                    if(pakage.find(Pair[*it][j])!=pakage.end()){
                        flag=0;
                        break;
                    }
                }
                if(!flag) break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
