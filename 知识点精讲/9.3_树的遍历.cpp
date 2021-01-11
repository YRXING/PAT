//树的静态写法
struct node{
    typename data;
    vector<int> child;//指针域，存放所有子结点的下标
}Node[maxn];
//如果只需要结构而不需要数据可以简化为vector数组"vector<int> child[maxn]"
//新建结点
int index=0;
int newNode(typename v){
    Node[index].data=v;
    Node[index].child.clear();//清空子结点
    return index++;
}
//一般考试涉及树都给出了结点的编号，可以直接作为数组下标

//先根遍历
void preorder(int root){
    printf(Node[root].data);
    for(int i=0;i<Node[root].child.size();i++)
        preorder(Node[root].child[i]);
}

//层序遍历
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


