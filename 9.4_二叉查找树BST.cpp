//对二叉查找树进行中序遍历，结果是有序序列

//查找
void search(node* root,typename x){
    if(root==NULL){
        printf("search failed\n");
        return;
    }
    if(x==root->data) printf(root->data);
    else if(x<root->data) search(root->lchild,x);
    else search(root->rchild,x);
}
//相比于普通二叉树，BST查找在与左右子树选择递归

//插入
void insert(node* &root,typename x){
    if(root==NULL){//查找失败,也即插入位置
        root = newNode(x);
        return;
    }
    if(x==root->data) return;
    else if(x<root->data) insert(root->lchild,x);
    else insert(root->rchild,x);
}

//建立
node* create(typename data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++)
        insert(root,data[i]);
    return root;
}
//插入顺序不同，生成的BST也可能不同,插入顺序也就可能不是先序序列

//删除
//1.删除前驱；2.删除后继
//寻找root为根的树中的最大结点
node* findMax(node* root){
    while(root->rchild!=NUll)
        root = root->rchild;
    return root;
}
node* findMin(node* root){
    while(root->lchild!=NULL)
        root = root->lchild;
    return root;
}

void deleteNode(node* root,typename x){
    if(root==NULL) return;
    if(root->data==x){
        if(root->lchild!=NULL){//前驱结点代替，删除前驱
            node* pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild,pre->data)
        }else if(root->rchild!=NULL){//后继结点代替，删除后继
            node* next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild,next->data);
        }else root==NULL;
    }else if(x<root->data) deleteNode(root->lchild,x);
    else deleteNode(root->rchild,x);
}
/*总是优先删除前驱或者后继容易导致左右子树高度极度不平衡，
使得二叉树退化成一条链，解决办法：
1.每次交替删除前驱或后继
2.记录子树高度，总是优先在高度较高的一颗子树里删除结点
*/
