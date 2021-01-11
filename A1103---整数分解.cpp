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
//0的任何次幂都是0,1的任何次幂都是1
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
1.多方案判断是否更优的时间复杂度最好是O（1）,否则容易超时。
因此必须在DFS的参数中记录当前底数之和sumSqu
2.不要在找到一组解时才判断temp序列与ans序列的字典关系，而应该让index从小到大进行选择，
这样index大的就会相对早地被选中。
*/
