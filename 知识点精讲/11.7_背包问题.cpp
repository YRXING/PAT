/*0-1背包问题
有n件物品，每件物品的重量为w[i],价值为c[i],现有容量为V的背包，如何选物品，使
背包里的价值最大，每件物品只有1件。
1.dp[i][v]表示前i件物品(1<=i<=n,0<=v<=V)恰好装入容量为v的背包中所能获得的最大价值.
2.dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i])  (1<=i<=n,w[i]<=v<=V)
3.边界：dp[0][v]=0.
4.枚举dp[n][v](0<=v<=V)取其最大值
*/
for(int i=1;i<=n;i++){
    for(int v=w[i];v<=V;v++){
        dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i]);
    }
}

//由于计算dp[i][v]时候只需要左上方和正上方的数据，不防开一个一维数组dp[v]
//dp[v]=max(dp[v],dp[v-w[i]]+c[i])  由于滚动更新涉及到数据的覆盖，所以一定要注意枚举顺序
//在这里v必须逆序枚举!!!!
for(int i=1;i<=n;i++)
for(int v=V;v>=w[i];v--){
    dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
    //choice[i][v]=0/1;
}

int k=n,num=0;//从第n件物品开始枚举
while(k>0){
    if(choice[k][v]==1){
        flag[k]=true;
        v-=w[i];
        num++;
    }
    else flag[k]=false;
    k--;
}

//0-1背包问题每一个物品都可以看做一个阶段dp[i][0]-dp[i][V],均由上一个阶段得到.
//对能都划分阶段的问题，都可以把阶段作为状态的一维.

/*完全背包问题
每件物品有无穷件
1.dp[i][v]表示前i件物品恰好放入v的背包所获得的最大值
2.dp[i][v]=max(dp[i-1][v],dp[i][v-w[i]+c[i]);
3.边界dp[0][v]=0;

一维形式dp[v]=max(dp[v],dp[v-w[i]]+c[i]);边界dp[v]=0;
形式和0-1完全一样,唯一区别就是v是正向枚举!!!
*/
for(int i=1;i<=n;i++)
for(int v=w[i];v<=V;v++){
    dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
}

