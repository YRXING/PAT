/*
1.����һ������Q�������������Ϊ0�Ľ��������
2.ȡ���׽�㣬�����Ȼ��ɾȥ���д��������ıߣ�������Щ�ߵ���Ķ������ȼ�1.
  ���ĳ���������ȼ�Ϊ0������������
3.��������2������ֱ������Ϊ�ա��������Ϊ��ʱ����ӵĽ����Ŀǡ��ΪN��˵���������гɹ�
*/
vector<int> G[maxv];
int n,m,inDegree[maxv];

bool topologicalSort(){
    int num=0;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(inDegree[i]==0) q.push(i);
    } //1.

    while(!q.empty()){//2.
        int u=q.front();
        //print("%d",u);
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            inDegree[v]--;
            if(inDegree[v]==0) q.push(v);
        }
        G[u].clear();//��ն���u�����г���(���ޱ�Ҫ,�ɲ�д)
        num++;
    }
    if(num==n) return true;
    else return false;
}
