#include <cstdio>
const int MAX = 31;

struct Node{
    int data;
    Node *left, *right;
}*root;
int n, num = 0;
int pre[MAX], post[MAX];
bool judge = true;

Node* create(int prel, int prer, int postl, int postr){
    if(postl > postr) return NULL;
    Node* root = new Node;
    root->data = pre[prel];
    if(postl == postr){
        root->left = root->right =NULL;
        return root;
    }
    int k;
    for(int i = postl; i <= postr; i++){
        if(post[i] == pre[prel+1]){
            k = i;
            break;
        }
    }
    if(k == postr-1) judge = false;
    int leftlen = k - postl+1;
    root->left = create(prel+1, prel+leftlen, postl, k);
    root->right = create(prel+leftlen+1, prer, k+1, postr-1);
    return root;
}

int isfirst=1;
void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        if(isfirst) {printf("%d",root->data);isfirst=0;}
        else printf(" %d",root->data);
        inorder(root->right);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    root = create(0, n-1, 0, n-1);
    if(judge) printf("Yes\n");
    else printf("No\n");
    inorder(root);
    return 0;
}

/*
1.要分出左右子树，在后序序列中找到先序序列pre[preL+1]的位置k，
则后序中k及k左侧的位左子树，k右侧的位右子树
2.不唯一：当k恰好等于postR-1的时候，不唯一，因为这个时候二叉树是
单支的，但是无法确定是左子树还是右子树
*/
