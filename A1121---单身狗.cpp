#include<cstdio>
#include<map>
#include<set>
using namespace std;
int isfirst=1;
map<int,int> Pair;
set<int> Party,result;

void printdata(int x){
    if(isfirst) {printf("%05d",x);isfirst=0;}
    else printf(" %05d",x);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Pair[a]=b;
        Pair[b]=a;
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int a;
        scanf("%d",&a);
        Party.insert(a);
    }
    for(set<int>::iterator it=Party.begin();it!=Party.end();it++){
        if(Pair.find(*it)==Pair.end()) result.insert(*it);
        else {
            int com=Pair[*it];
            if(Party.find(com)==Party.end()) result.insert(*it);
        }
    }

    printf("%d\n",result.size());
    for(set<int>::iterator it=result.begin();it!=result.end();it++)
        printdata(*it);
    return 0;
}
