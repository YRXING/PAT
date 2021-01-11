//左右子树高度之差为平衡因子，平衡因子的绝对值不超过1
struct node{
    int v,height;
    node *lchild,*rchild;
};

node* newNode(int v){
    node* Node = new node;
    Node->v = v;
    Node->height = 1;//多一步初始化结点高度
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node* root){
    if(root==NULL) return 0;
    return root->height;
}

int getBalanceFactor(node* root){
    return getHeight(root->lchild)-getHeight(root->rchild);
}

//root所在子树的height等于其左子树height与右子树height的较大值加1
void updateHeight(node* root){
    root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

//查找,和BST一样

//平衡操作 v
void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);//root右子树发生变化，需要更新
    updateHeight(temp);//temp左子树发生变化，需要更新
    root = temp;
}

void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//只要把最靠近插入结点的失衡结点调整到正常，即可，失衡结点平衡因子为2或-2
/*
---------------------------------------------------------------------
LL      BF(root)=2,BF(root->lchild)=1       root右旋
---------------------------------------------------------------------
LR      BF(root)=2,BF(root->lchild)=-1      root->lchild左旋,root右旋
---------------------------------------------------------------------
RR      BF(root)=-2,BF(root->rchild)=-1     root左旋
---------------------------------------------------------------------
RL      BF(root)=-2,BF(root->rchild)=1      root->rchild右旋,root左旋
---------------------------------------------------------------------
*/
//插入代码是在二叉查找树上增加平衡操作
void insert(node* &root,int v){
    if(root==NULL){
        root = newNode(v);
        return;
    }
    if(v<root->v){
        insert(root->lchild,v);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->lchild)==1){//LL形
                R(root);
            }else if(getBalanceFactor(root->lchild)==-1){//LR形
                L(root->lchild);
                R(root);
            }
        }else{
            insert(root->rchild,v);
            updateHeight(root);
            if(getBalanceFactor(root==-2)){
                if(getBalanceFactor(root->rchild)==-1){//RR形
                    L(root);
                }
                else if(getBalanceFactor(root->rchild)==1){//RL形
                    R(root->rchild);
                    L(root);
                }
            }
        }
    }
}

node* Create(int data[],int n){
    node* root = NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

