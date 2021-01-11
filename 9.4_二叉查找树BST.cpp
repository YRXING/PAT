//�Զ����������������������������������

//����
void search(node* root,typename x){
    if(root==NULL){
        printf("search failed\n");
        return;
    }
    if(x==root->data) printf(root->data);
    else if(x<root->data) search(root->lchild,x);
    else search(root->rchild,x);
}
//�������ͨ��������BST����������������ѡ��ݹ�

//����
void insert(node* &root,typename x){
    if(root==NULL){//����ʧ��,Ҳ������λ��
        root = newNode(x);
        return;
    }
    if(x==root->data) return;
    else if(x<root->data) insert(root->lchild,x);
    else insert(root->rchild,x);
}

//����
node* create(typename data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++)
        insert(root,data[i]);
    return root;
}
//����˳��ͬ�����ɵ�BSTҲ���ܲ�ͬ,����˳��Ҳ�Ϳ��ܲ�����������

//ɾ��
//1.ɾ��ǰ����2.ɾ�����
//Ѱ��rootΪ�������е������
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
        if(root->lchild!=NULL){//ǰ�������棬ɾ��ǰ��
            node* pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild,pre->data)
        }else if(root->rchild!=NULL){//��̽����棬ɾ�����
            node* next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild,next->data);
        }else root==NULL;
    }else if(x<root->data) deleteNode(root->lchild,x);
    else deleteNode(root->rchild,x);
}
/*��������ɾ��ǰ�����ߺ�����׵������������߶ȼ��Ȳ�ƽ�⣬
ʹ�ö������˻���һ����������취��
1.ÿ�ν���ɾ��ǰ������
2.��¼�����߶ȣ����������ڸ߶Ƚϸߵ�һ��������ɾ�����
*/
