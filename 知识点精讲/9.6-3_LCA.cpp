//两个结点在这颗书上深度最大的公共祖先结点

/*Tarjan（离线）算法，在一次遍历中把左右询问一次性解决
时间复杂度O(n+q)
1.任选一个点为根节点，从根节点开始
2.遍历该点u所有子结点v，并标记这些子结点v已访问过
3.若v还有子结点，返回2，否则下一步
4.合并v到u上。
5.寻找当前点u有询问关系的点v
6.若是v已经被访问过了，则可以确认u和v的最近公共祖先为v被合并到的父亲结点a

初始化father数组和vis数组
Tarjan(u){
    for each(u,child){
        Tarjan(child);
        merge(u,child);
        标记child被访问过;
    }
    for each(u,e){
        如果e被访问过；
        u,e的最近公共祖先为find(e);
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

/*倍增
在线求LCA，
<1> 暴力算法
1.如果a和b深度不同，先把深度调浅，使他变得和浅的那个一样
2.把两个一起一步一步往上移动，直到他们到达最近公共祖先

void dfs(int prev,int rt){//获得father数组和depth数组
    depth[rt]=depth[prev]+1;
    father[rt]=prev;
    for each(rt孩子v)
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
1.把a和b移到同一深度，从大到小枚举k，如果b向上跳2^k深度>=depth_a,那么往上跳
2.如果a=b,那么显然LCA就是a，否则3.
3.分别找到最浅的a'和b'（两者不等），在利用倍增，从大到小枚举k,
  如果对于当前k，a和b的第2^k个祖先不同，那么a和b都跳到2^k祖先的位置
  LCA就是anc[a][0]或anc[b][0];

int anc[N][N];//anc[i][j]第i个结点网上2^j个祖先
int deep[N];

void DFS(int prev,int rt){
    depth[rt]=depth[prev]+1;
    anc[rt][0]=prev;
    for(int i=1;i<20;i++)
        anc[rt][i]=anc[anc[rt][i-1]][i-1];
    for each(rt孩子v)
        dfs(rt,v);
}

int LCA(int x,int y){
    if(depth[x]<depth[y]) swap(x,y);
    for(int i=19;i>=0;i--)
        if(depth[x]-(1<<i)>=depth[y]) x=anc[x][i];//深度相同,=不可以丢掉

    if(x==y) return x;
    for(int i=19;i>=0;i--)
        if(anc[x][i]!=anc[y][i])
            x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

<3> 利用栈+后序遍历
