//����������������������Ĺ������Ƚ��

/*Tarjan�����ߣ��㷨����һ�α����а�����ѯ��һ���Խ��
ʱ�临�Ӷ�O(n+q)
1.��ѡһ����Ϊ���ڵ㣬�Ӹ��ڵ㿪ʼ
2.�����õ�u�����ӽ��v���������Щ�ӽ��v�ѷ��ʹ�
3.��v�����ӽ�㣬����2��������һ��
4.�ϲ�v��u�ϡ�
5.Ѱ�ҵ�ǰ��u��ѯ�ʹ�ϵ�ĵ�v
6.����v�Ѿ������ʹ��ˣ������ȷ��u��v�������������Ϊv���ϲ����ĸ��׽��a

��ʼ��father�����vis����
Tarjan(u){
    for each(u,child){
        Tarjan(child);
        merge(u,child);
        ���child�����ʹ�;
    }
    for each(u,e){
        ���e�����ʹ���
        u,e�������������Ϊfind(e);
    }
}

void Tarjan(node* root){
    if(root->lchild){
        Tarjan(root->lchild);
        Union(root->data,root->lchild->data);
        vis[root->lchild->data]=1;
    }
    if(root->rchild){
        Tarjan(root->rchild);
        Union(root->data,root->rchild->data);
        Union(root->data,root->rchild->data);
        vis[root->rchild->data]=1;
    }
    for(int i=0;i<relate[root->data].size();i++){
        int e=relate[root->data][i];
        if(vis[e]&&!LCA[root->data][e]) LCA[root->data][e]=LCA[e][root->data]=findFather(e);
    }
}
*/

/*����
������LCA��
<1> �����㷨
1.���a��b��Ȳ�ͬ���Ȱ���ȵ�ǳ��ʹ����ú�ǳ���Ǹ�һ��
2.������һ��һ��һ�������ƶ���ֱ�����ǵ��������������

void dfs(int prev,int rt){//���father�����depth����
    depth[rt]=depth[prev]+1;
    father[rt]=prev;
    for each(rt����v)
        dfs(rt,v);
}

int LCA(int a,int b){
    if(depth[a]>depth[b]) swap(a,b);
    while(depth[b]>depth[a]) b=father[b];
    while(a!=b)
        a=father[a],b=father[b];
    return a;
}

<2>
1.��a��b�Ƶ�ͬһ��ȣ��Ӵ�Сö��k�����b������2^k���>=depth_a,��ô������
2.���a=b,��ô��ȻLCA����a������3.
3.�ֱ��ҵ���ǳ��a'��b'�����߲��ȣ��������ñ������Ӵ�Сö��k,
  ������ڵ�ǰk��a��b�ĵ�2^k�����Ȳ�ͬ����ôa��b������2^k���ȵ�λ��
  LCA����anc[a][0]��anc[b][0];

int anc[N][N];//anc[i][j]��i���������2^j������
int deep[N];

void DFS(int prev,int rt){
    depth[rt]=depth[prev]+1;
    anc[rt][0]=prev;
    for(int i=1;i<20;i++)
        anc[rt][i]=anc[anc[rt][i-1]][i-1];
    for each(rt����v)
        dfs(rt,v);
}

int LCA(int x,int y){
    if(depth[x]<depth[y]) swap(x,y);
    for(int i=19;i>=0;i--)
        if(depth[x]-(1<<i)>=depth[y]) x=anc[x][i];//�����ͬ,=�����Զ���

    if(x==y) return x;
    for(int i=19;i>=0;i--)
        if(anc[x][i]!=anc[y][i])
            x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

<3> ����ջ+�������
