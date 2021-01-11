#include<stdio.h>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int> > v(10000);
int visit[10000], minCnt, minTransfer, start, end1;//最少经过的站，最少换成的站
map<int, int> line;//两个站点对应的线路，前一个Int可以把两个站点拼接起来
vector<int> path, tempPath;

int transferCnt(vector<int> a){//寻找路径中转换的站点次数
    int cnt=-1,preline=0;
    for(int i=1;i<a.size();i++){
        if(line[a[i-1]*10000+a[i]]!=preline) cnt++;
        preline=line[a[i-1]*10000+a[i]];
    }
    return cnt;
}
void dfs(int node,int cnt){
    if(node==end1&&(cnt<minCnt||(cnt==minCnt&&transferCnt(tempPath)<minTransfer))){
        minCnt=cnt;
        minTransfer=transferCnt(tempPath);
        path=tempPath;
        return;
    }
    for(int i=0;i<v[node].size();i++){
        if(visit[v[node][i]]==0){
            visit[v[node][i]]=1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i],cnt+1);

            visit[v[node][i]]=0;//回溯
            tempPath.pop_back();
        }
    }
}

int main(){
    int n,m,k,pre,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&m,&pre);
        for(int j=1;j<m;j++){
            scanf("%d",&temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre*10000+temp]=line[temp*10000+pre]=i+1;
            pre=temp;
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&start,&end1);
        minCnt=99999,minTransfer=99999;
        tempPath.clear();
        tempPath.push_back(start);
        visit[start]=1;
        dfs(start,0);
        visit[start]=0;
        printf("%d\n",minCnt);
        int preline=0,preTransfer=start;
        for(int j=1;j<path.size();j++){
            if(line[path[j-1]*10000+path[j]]!=preline){
                if(preline!=0) printf("Take Line#%d from %04d to %04d.\n",preline,preTransfer,path[j-1]);
                preline=line[path[j-1]*10000+path[j]];
                preTransfer=path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, preTransfer, end1);//最后一段要输出
    }
    return 0;
}
/*一遍DFS，维护两个变量，minCnt中途经停最少的站；
minTransfer-需要换乘最小的次数
1.计算一条线路换成的次数:line[10000][10000]保存每两个相邻站间的线路是几号线
，从头到尾遍历最终保存的路径，preline为前一段线路编号，当前节点和前一个节点
组成的线路和preline不同，说明有一个换成,cnt+1
2.计算中途停站次数:每次dfs将cnt+1;
3.输出结果：和计算线路换成次数的西路一样，每当preline和line不同时候就输出一句话
  保存preTransfer表示上一个换成站，最后不要忘记输出preTransfer和最后一站之间的路，
  即使最后一站并不是换乘站.
*/
