#include<stdio.h>
#include<queue>
using namespace std;

//����С���ѵ����ȶ���
priority_queue<long long,vector<long long>,greater<long long> >q;

int main(){
    int n;
    long long temp,x,y,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        q.push(temp);
    }
    while(q.size()>1){//ֻҪ���ȶ���������������Ԫ��
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x+y);
        ans+=x+y;
    }
    printf("%lld\n",ans);
    return 0;
}
