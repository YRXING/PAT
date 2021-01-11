/*动态规划会将每个求解过的子问题的解记录下来，这样当下一下次
碰到同样的子问题，就可以直接使用之前记录的结果，而不是重复计算
一般有递归（记忆化搜索）和递推写法，如何设置状态和状态转移方程
是核心
*/

//递推写法（数塔问题）
//第一层一个数字，第n层n个数字，从第一层走到第n层，路径上数字和最大是多少
dp[i][j]//表示从i,j位置出发到达最底层的最大值
dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+f[i][j]
//dp[i][j]称为问题的状态,上述式子为状态转移方程.
dp[n][j]=f[n][j](1<=j<=n)//动态规划的递推写法总是从这些边界出发，通过状态转移方程扩散到整个dp数组
//核心代码
for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
        scanf("%d",&f[i][j]);

for(int j=1;j<=n;j++)
    dp[n][j]=f[n][j];

for(int i=n-1;i>=1;i--)
    for(int j=1;j<=i;j++)
        dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+f[i][j];

//递推写法是自低向上的(从边界出发)，递归写法是自顶向下的(到边界返回)。

/*最大连续子序列和
给定一个数字序列A1,A2,A3...An，使得Ai+...+Aj最大,输出最大和
1.dp[i]表示已A[i]作为末尾的连续序列的最大和
2.dp[i]=max(dp[i-1]+A[i],A[i])
3.边界dp[0]=A[0]
*/
dp[0]=A[0];
for(int i=1;i<n;i++)
    dp[i]=max(dp[i-1]+A[i],A[i]);
//输出dp[i]的最大值

/*最长不下降子序列(Longest Increasing Sequence,LIS)
在一个数字序列中，找到一个最长的子序列（可以不连续）,使得子序列非递减
1.令dp[i]表示以A[i]结尾的最长不下降子序列长度
2.dp[i]=max(1,dp[j]+1)  (j=1,2,...i-1&&A[j]<A[i])
3.边界dp[i]=1 (1<=i<=n)
*/
int ans=-1;
for(int i=1;i<=n;i++){
    dp[i]=1;
    for(int j=1;j<i;j++){
        if(A[j]<A[i]&&dp[j]+1>d[i])
            dp[i]=dp[j]+1;
    }
    ans=max(ans,dp[i]);
}
printf(ans);

/*最长公共子序列(longest Common Subsequence,LCS)
给定两个字符串（或数字序列）A和B，求一个字符串，使得这个字符串是A和B的最
长公共部分（子序列可以不连续）
1.dp[i][j]表示A的i号位和B的j号位之前的LCS长度
2.             dp[i-1][j-1]+1, A[i]==B[j];
    dp[i][j]=
               max(dp[i-1][j],dp[i][j-1]), A[i]!=B[j];
3.边界dp[i][0]=dp[0][j]=0 (0<=i<=n,0<=j<=m)
*/
gets(A+1);
gets(B+1);
int lenA = strlen(A+1);
int lenB = strlen(B+1);
for(int i=0;i<=lenA;i++)
    dp[i][0]=0;
for(int j=0;j<=lenB;j++)
    dp[0][j]=0;
for(int i=1;i<=lenA;i++)
for(j=1;j<=lenB;j++){
    if(A[i]==B[j]) dp[i][j] = dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}
printf(dp[lenA][lenB]);

/*最长回文串
给出一个字符串S，求S的最长会问子串的长度
1.dp[i][j]表示S[i]到S[j]所表示的子串是否是回文串，是为1，不是为0
2.              dp[i+1][j-1],S[i]==S[j];
    dp[i][j]=
                0,S[i]!=S[j];
3.边界dp[i][i]=1,dp[i][i+1]=(S[i]==S[i][i+1]?1:0)
4.正常枚举得不到完成的dp
*/
gets(S);
int len=strlen(S),ans=1;
memset(dp,0,sizeof(dp));

for(int i=0;i<len;i++){
    dp[i][i]=1;
    if(i<len-1){
        if(S[i]==S[i+1]){
            dp[i][i+1]=1;
            ans=2;
        }
    }
}

for(int L=3;L<=len;L++){//枚举子串长度
    for(int i=0;i+L-1<len;i++){//枚举子串的起始端点
        int j=i+L-1;//子串右端点
        if(S[i]==S[j]&&dp[i+1][j-1]==1){
            dp[i][j]=1;
            ans=L;
        }
    }
}
printf(ans);
