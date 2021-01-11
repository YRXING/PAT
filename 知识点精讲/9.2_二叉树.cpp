/*���ʣ�
1.������ͨ���������ڶ�������һ�Ľṹһ����һ����
2.������Ҷ�ӽڵ㾭�����������߽�����
3.����������Զ����£��߶����Ե����ϣ��������ԣ���Ⱥ͸߶���ͬ
4.�Լ������Լ������Ƚ�㣬Ҳ���Լ���������
*/

//����������ʽ�洢
struct node{
    typename data;
    node* lchild;
    node *rchild;
};

//��ȫ����������������洢,x�������2x,�Һ���2x+1�����ڵ�1��
//root*2>n��root��Ҷ��㣬root>n��root�ǿսڵ�
//�����½ڵ�
node* newNode(typename v){
    node* Node = new node;
    Node->data = v;
    Node->lchild=Node->rchild=NULL;
    return Node;
}
//����,�޸�
void search(node* root,typename x){
    if(root==NULL) return;
    if(root->data==x) root->data=data;
    search(root->lchild);
    search(root->rchild);
}
//����
void insert(node* &root,typename x){
    if(root==NULL){
        root = newNode(x);//����ʧ�ܣ�Ҳ������λ��
        return;
    }
    if(�ɶ��������ʣ�xӦ�ò���������)
        insert(root->lchild,x);
    else insert(root->rchild,x);
}
//����������
node* Create(typename data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

//������������򡢺���ݹ�д��
void preorder(node* root){
    if(root==NULL) return;
    printf(root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

//�������
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

//����ÿ����������Ĳ��
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

//��֪�������к��������У��ؽ�������
//��ǰ����[preL,preR],����[inL,inR]
node* create(int preL,int preR,int inL,int inR){
    if(preL>preR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k=inL;k<=inR;k++)//Ѱ��k��λ��
        if(in[k]==pre[preL]) break;
    int numLeft = k-inL;

    root->lchild = create(preL+1,preL+numLeft,inL,k-1);
    root->rchild = create(preL+numLeft+1,preR,k+1,inR);
    return root;
}

//�������򣬽���
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
