//���������߶�֮��Ϊƽ�����ӣ�ƽ�����ӵľ���ֵ������1
struct node{
    int v,height;
    node *lchild,*rchild;
};

node* newNode(int v){
    node* Node = new node;
    Node->v = v;
    Node->height = 1;//��һ����ʼ�����߶�
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

//root����������height������������height��������height�Ľϴ�ֵ��1
void updateHeight(node* root){
    root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

//����,��BSTһ��

//ƽ����� v
void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);//root�����������仯����Ҫ����
    updateHeight(temp);//temp�����������仯����Ҫ����
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

//ֻҪ������������ʧ������������������ɣ�ʧ����ƽ������Ϊ2��-2
/*
---------------------------------------------------------------------
LL      BF(root)=2,BF(root->lchild)=1       root����
---------------------------------------------------------------------
LR      BF(root)=2,BF(root->lchild)=-1      root->lchild����,root����
---------------------------------------------------------------------
RR      BF(root)=-2,BF(root->rchild)=-1     root����
---------------------------------------------------------------------
RL      BF(root)=-2,BF(root->rchild)=1      root->rchild����,root����
---------------------------------------------------------------------
*/
//����������ڶ��������������ƽ�����
void insert(node* &root,int v){
    if(root==NULL){
        root = newNode(v);
        return;
    }
    if(v<root->v){
        insert(root->lchild,v);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->lchild)==1){//LL��
                R(root);
            }else if(getBalanceFactor(root->lchild)==-1){//LR��
                L(root->lchild);
                R(root);
            }
        }else{
            insert(root->rchild,v);
            updateHeight(root);
            if(getBalanceFactor(root==-2)){
                if(getBalanceFactor(root->rchild)==-1){//RR��
                    L(root);
                }
                else if(getBalanceFactor(root->rchild)==1){//RL��
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

