/*����һ��DAGͼ�����·��(���̶������յ�)
1.dp[i]��ʾ��i�Ŷ�������ܻ�õ��·������(����dp[i]���ֵ��Ϊ����)
2.dp[i]=max(dp[j]+length[i->j]) (��Ҫ������������˳�����dp������ߵݹ�)
  ���dp[i]��ʾ��i�Ŷ����β���·������
  dp[i]=max(dp[j]+length[j->i])��
3.�ӳ���Ϊ0�Ķ�������·��Ϊ0����˱߽�ֵdpΪ0��������ʵ�ֶ�����dp�����ʼ��Ϊ0
*/

int DP(int i){
    if(dp[i]>0) return dp[i];//dp[i]�Ѽ���õ�
    for(int j=0;j<n;j++){//��������i�ĳ���
        if(G[i][j]!=INF){
            dp[i]=max(dp[i],DP(j)+G[i][j]);
        }
    }
    return dp[i];
}

//������Dijkstra����һ��int��choice�����¼�·���϶���ĺ�̶���
//��������ж����������Ϊvector
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

/*����ж��������ֵ�����̵���һ����ֻ���������������������֣������С�����ȸ���
�����н�ǰ�Ĳ������жϣ����������Խ��ǰ�Ķ���,��dpֵӦ��Խ������㡣
*/

/*�̶��յ㣬��DAG�·
1.dp[i]��ʾ��i�Ŷ����������T���·��
2.dp[i]=max(dp[j]+lenth[i->j])
3.Ψһ�������Ǳ߽�:dp[T]=0;���ܶ�����dp���鸳Ϊ0�����ǳ�ʼ��Ϊ-INF����ʾ���ɴ����vis����
  ��ʾ�Ѿ�������,û�б�����˵������·���յ�һ������T�������̶��յ����е��dpֵ���ܱ�����
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

//����Ƕ������
//�����ο���һ�����㣬����Ƕ�׹�ϵ��Ϊ����֮�������ߣ���Ȩ��Ϊ1�����Ǿ�ת��Ϊ��DAG�·

