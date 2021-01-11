#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int N,K,P,maxSumSqu=-1;
vector<int> temp,ans,fac;

int power(int x){
    int ans=1;
    for(int i=0;i<P;i++){
        ans = ans*x;
    }
    return ans;
}
//0���κδ��ݶ���0,1���κδ��ݶ���1
void init(){
    int i=0,temp=0;
    while(temp<=N){
        fac.push_back(temp);
        temp = power(++i);
    }
}

void DFS(int index,int nowK,int sum,int sumSqu){
    if(nowK==K&&sum==N){
        if(sumSqu>maxSumSqu){
            maxSumSqu = sumSqu;
            ans=temp;
        }
        return;
    }
    if(nowK>K||sum>N) return;
    if(index-1>=0){
        temp.push_back(index);
        DFS(index,nowK+1,sum+fac[index],sumSqu+index);
        temp.pop_back();
        DFS(index-1,nowK,sum,sumSqu);
    }
}
int main(){
    scanf("%d%d%d",&N,&K,&P);
    init();
    DFS(fac.size()-1,0,0,0);
    if(ans.empty()) printf("Impossible");
    else {
        printf("%d =",N);
        for(int i=0;i<ans.size()-1;i++)
            printf(" %d^%d +",ans[i],P);
        printf(" %d^%d",ans[ans.size()-1],P);
    }
    return 0;
}

/*
1.�෽���ж��Ƿ���ŵ�ʱ�临�Ӷ������O��1��,�������׳�ʱ��
��˱�����DFS�Ĳ����м�¼��ǰ����֮��sumSqu
2.��Ҫ���ҵ�һ���ʱ���ж�temp������ans���е��ֵ��ϵ����Ӧ����index��С�������ѡ��
����index��ľͻ������ر�ѡ�С�
*/
