#include<cstdio>
#include<set>
using namespace std;
const int N=51;
set<int> sets[N];
int share(set<int> s1,set<int> s2){
    set<int>::iterator it1=s1.begin(),it2=s2.begin();
    int ans=0;
    while(it1!=s1.end()&&it2!=s2.end()){
        if(*(it1)==*(it2)){ans++;it1++;it2++;}
        else if(*(it1)>*(it2)) it2++;
        else it1++;
    }
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            int num;
            scanf("%d",&num);
            sets[i].insert(num);
        }
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int s1,s2;
        scanf("%d%d",&s1,&s2);
        int share_num=share(sets[s1],sets[s2]);
        int total_num=sets[s1].size()+sets[s2].size()-share_num;
        printf("%.1lf%%\n",share_num*1.0/total_num*100);
    }
    return 0;
}
