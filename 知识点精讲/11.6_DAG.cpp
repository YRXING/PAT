/*给定一个DAG图，求最长路径(不固定起点跟终点)
1.dp[i]表示从i号顶点出发能获得的最长路径长度(所有dp[i]最大值即为所得)
2.dp[i]=max(dp[j]+length[i->j]) (需要按逆拓扑序列顺序求解dp数组或者递归)
  如果dp[i]表示以i号顶点结尾的最长路径长度
  dp[i]=max(dp[j]+length[j->i])。
3.从出度为0的顶点出发最长路径为0，因此边界值dp为0，但具体实现对整个dp数组初始化为0
*/

int DP(int i){
    if(dp[i]>0) return dp[i];//dp[i]已计算得到
    for(int j=0;j<n;j++){//遍历所有i的出边
        if(G[i][j]!=INF){
            dp[i]=max(dp[i],DP(j)+G[i][j]);
        }
    }
    return dp[i];
}

//类似于Dijkstra，开一个int型choice数组记录最长路径上顶点的后继顶点
//如果最终有多条，数组改为vector
int DP(int i){
    if(d[i]>0) return dp[i];
    for(int j=0;j<n;j++){
        if(G[i][j]!=INF){
            int temp = DP(j)+G[i][j];
            if(temp>dp[i]){
                dp[i]=temp;
                choice[i]=j;
            }
        }
    }
    return dp[i];
}

void printPath(int i){
    printf("%d",i);
    while(choice[i]!=-1){
        i = choice[i];
        printf("->%d",i);
    }
}

/*如果有多条，求字典序最短的那一条，只能用逆拓扑序列求。由于字，典序大小总是先根据
序列中较前的部分来判断，因此序列中越靠前的顶点,其dp值应当越往后计算。
*/

/*固定终点，求DAG最长路
1.dp[i]表示从i号顶点出发到达T的最长路径
2.dp[i]=max(dp[j]+lenth[i->j])
3.唯一的区别是边界:dp[T]=0;不能对整个dp数组赋为0，而是初始化为-INF来表示不可达，设置vis数组
  表示已经被计算,没有被计算说明这条路的终点一定不是T。而不固定终点所有点的dp值都能被计算
*/
int DP(int i){
    if(vis[i]) return dp[i];
    vis[i]=true;
    for(int j=0;j<n;j++){
        if(G[i][j]!=INF){
            dp[i]=max(dp[i],DP(j)+G[i][j]);
        }
    }
    return dp[i];
}

//矩形嵌套问题
//将矩形看成一个顶点，并将嵌套关系视为顶点之间的有向边，边权均为1，于是就转化为求DAG最长路
/*
题意描述：有n个矩形，每个矩形可以用两个整数a、b描述，表示它的长和宽，矩形（a,b）可以嵌套在矩形(c,d)当且仅当a<c且b<d,
要求选出尽量多的矩形排成一排，使得除了最后一个外，每一个矩形都可以嵌套在下一个矩形内，如果有多解，矩形编号的字典序应尽量小
矩形之间的可嵌套关系是一个"二元关系"，二元关系可以用图来建模。
如果矩形X可以嵌套在矩形Y里，就从X到Y连一条有向边（G[x][y]=1）。
这个图是无环的，因为一个矩形无法直接或间接地嵌套在自己内部，换句话说，他是一个DAG。这样，原问题便转化为求DAG上的最长路径。
*/
