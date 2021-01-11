/*性质：
1.满足联通、边数等于顶点数减一的结构一定是一棵树
2.空树和叶子节点经常被用来出边界数据
3.结点的深度是自顶向下，高度是自底向上，对树而言，深度和高度相同
4.自己既是自己的祖先结点，也是自己的子孙结点
*/

//二叉树的链式存储
struct node{
    typename data;
    node* lchild;
    node *rchild;
};

//完全二叉树可以用数组存储,x结点左孩子2x,右孩子2x+1，根节点1！
//root*2>n，root是叶结点，root>n，root是空节点
//生成新节点
node* newNode(typename v){
    node* Node = new node;
    Node->data = v;
    Node->lchild=Node->rchild=NULL;
    return Node;
}
//查找,修改
void search(node* root,typename x){
    if(root==NULL) return;
    if(root->data==x) root->data=data;
    search(root->lchild);
    search(root->rchild);
}
//插入
void insert(node* &root,typename x){
    if(root==NULL){
        root = newNode(x);//查找失败，也即插入位置
        return;
    }
    if(由二叉树性质，x应该插在左子树)
        insert(root->lchild,x);
    else insert(root->rchild,x);
}
//创建二叉树
node* Create(typename data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

//先序遍历、中序、后序递归写法
void preorder(node* root){
    if(root==NULL) return;
    printf(root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

//层序遍历
void layerorder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf(now->data);
        if(now->lchild!=NULL) q.push(now->lchild);
        if(now->rchild!=NULL) q.push(now->rchild);
    }
}

//计算每个结点所处的层次
struct node{
    int data;
    int layer;
    node* lchild;
    node* rchild;
};
void layerorder(node* root){
    queue<queue> q;
    root->layer=1;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf(now->data);
        if(now->lchild!=NULL){
            now->lchild->layer=now->layer+1;
            q.push(now->lchild);
        }
        if(now->rchild!=NULL){
            now->rchild->rayer=now->rayer+1;
            q.push(now->rchild);
        }

    }
}

//已知先序序列和中序序列，重建二叉树
//当前先序[preL,preR],中序[inL,inR]
node* create(int preL,int preR,int inL,int inR){
    if(preL>preR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k=inL;k<=inR;k++)//寻找k的位置
        if(in[k]==pre[preL]) break;
    int numLeft = k-inL;

    root->lchild = create(preL+1,preL+numLeft,inL,k-1);
    root->rchild = create(preL+numLeft+1,preR,k+1,inR);
    return root;
}

//层序，中序，建树
vector<int> level;
int in[maxn];
int vis[maxn]={0};

node* create(int inL,int inR,vector<int> lev){
    if(inL>inR) return NULL;
    node* root=new node;
    root->data=lev[0];
    int k;
    for(k=inL;k<=inR;k++){
        if(in[k]==root->data) break;
    }
    for(int i=inL;i<k;i++){
        vis[in[i]]=true;
    }
    vector<int> levl,levr;
    for(int i=1;i<lev.size();i++){
        if(vis[lev[i]]) {
            levl.push_back(lev[i]);
            vis[lev[i]]=false;
        }
        else levr.push_back(lev[i]);
    }
    root->lchild=create(inL,k-1,levl);
    root->rchild=create(k+1,inR,levr);
    return root;
}
