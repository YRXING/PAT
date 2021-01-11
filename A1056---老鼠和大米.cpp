#include<stdio.h>
#include<queue>
using namespace std;
const int maxn=1010;
struct mouse{
    int wight;
    int rank;
}M[maxn];


int main(){
    int NP,NG,order;
    scanf("%d%d",&NP,&NG);
    for(int i=0;i<NP;i++)
        scanf("%d",&M[i].wight);
    queue<int> q;
    for(int i=0;i<NP;i++){
        scanf("%d",&order);
        q.push(order);
    }
    int group,temp=NP;
    while(q.size()!=1){
        if(temp%NG==0) group=temp/NG;
        else group=temp/NG+1;

        for(int i=0;i<group;i++){
            int k=q.front();

            for(int j=0;j<NG;j++){
                if(i*NG+j>=temp) break;
                int front = q.front();
                if(M[front].wight>M[k].wight){
                    k = front;
                }
                M[front].rank=group+1;
                q.pop();
            }

            q.push(k);//这一组最胖的
        }

        temp = group;
    }
    M[q.front()].rank=1;
    for(int i=0;i<NP;i++){
        if(i==0) printf("%d",M[i].rank);
        else printf(" %d",M[i].rank);
    }
    return 0;
}
