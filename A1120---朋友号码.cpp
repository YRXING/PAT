#include<cstdio>
#include<set>
#include<cstring>
using namespace std;

int friendNum(char str[]){
    int len=strlen(str);
    int ans=0;
    for(int i=0;i<len;i++)
        ans+=str[i]-'0';
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    char str[10];
    set<int> result;
    for(int i=0;i<n;i++){
        scanf("%s",str);
        result.insert(friendNum(str));
    }

    printf("%d\n",result.size());
    for(set<int>::iterator it=result.begin();it!=result.end();it++){
        if(it==result.begin()) printf("%d",*it);
        else printf(" %d",*it);
    }
    return 0;
}
