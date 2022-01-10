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

// 非递归写法
void preOrder2(node *root)     //非递归前序遍历 
{
    stack<node*> s;
    node *p=root; //遍历指针
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            cout<<p->data<<"";
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}

void inOrder2(node *root)      //非递归中序遍历
{
    stack<node*> s;
    BinTree *p=root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            cout<<p->data<<""; //和前序的区别就是pop的时候再去访问
            s.pop();
            p=p->rchild;
        }
    }    
}

/*
如果P不存在左孩子和右孩子，则可以直接访问它；
或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
*/
void postOrder2(node *root)     //非递归后序遍历
{
    stack<node*> s;
    node *cur;                      //当前结点 
    ndoe *pre=NULL;                 //前一次访问的结点 
    s.push(root);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL&&cur->rchild==NULL)||
           (pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            cout<<cur->data<<"";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
              s.pop();
            pre=cur; 
        }
        else
        {
            if(cur->rchild!=NULL) //要先push右子树，这样pop才是先访问的左，后访问的右
                s.push(cur->rchild);
            if(cur->lchild!=NULL)    
                s.push(cur->lchild);
        }
    }    
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
