//���ľ�̬д��
struct node{
    typename data;
    vector<int> child;//ָ���򣬴�������ӽ����±�
}Node[maxn];
//���ֻ��Ҫ�ṹ������Ҫ���ݿ��Լ�Ϊvector����"vector<int> child[maxn]"
//�½����
int index=0;
int newNode(typename v){
    Node[index].data=v;
    Node[index].child.clear();//����ӽ��
    return index++;
}
//һ�㿼���漰���������˽��ı�ţ�����ֱ����Ϊ�����±�

//�ȸ�����
void preorder(int root){
    printf(Node[root].data);
    for(int i=0;i<Node[root].child.size();i++)
        preorder(Node[root].child[i]);
}

//�������
void layerorder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int front = q.front();
        q.pop;
        printf(Node[front].data);
        for(int i=0;i<Node[front].child.size();i++)
            Q.push(Node[front].child[i]);
    }
}


