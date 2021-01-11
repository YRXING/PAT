#include<cstdio>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int M,N,K;
stack<int> s;
queue<int> popseq;

bool judge(){
    for(int i=1;i<=N;i++){
        s.push(i);
        if(s.size()>M) return false;
        while(!s.empty()&&s.top()==popseq.front()){
            s.pop();
            popseq.pop();
            if(popseq.empty()) return true;
        }
    }
    if(!s.empty()) return false;
}

int main(){
    scanf("%d%d%d",&M,&N,&K);
    while(K--){
        while(!popseq.empty()) popseq.pop();
        while(!s.empty()) s.pop();
        for(int i=0;i<N;i++){
            int num;
            scanf("%d",&num);
            popseq.push(num);
        }
        if(judge()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
