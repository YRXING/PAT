#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N=25;

struct node{
    int data,height;
    node *lchild,*rchild;
}*root;
int n,x;
vector<node*> vec;

node* newNode(int x){
    node* root=new node;
    root->data=x;
    root->height=1;
    root->lchild=root->rchild=NULL;
    return root;
}

int getHeight(node* root){
    if(root==NULL) return 0;
    return root->height;
}
void updateHeight(node* root){
    root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

int getBF(node* root){
    return getHeight(root->lchild)-getHeight(root->rchild);
}

void L(node* &root){
    node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void R(node* &root){
    node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}

void insert(node* &root,int v){
    if(root==NULL){
        root = newNode(v);
        return;
    }
    if(v<root->data){
        insert(root->lchild,v);
        updateHeight(root);
        if(getBF(root)==2){
            if(getBF(root->lchild)==1){//LL形
                R(root);
            }else if(getBF(root->lchild)==-1){//LR形
                L(root->lchild);
                R(root);
            }
        }
    }
    else{
            insert(root->rchild,v);
            updateHeight(root);
            if(getBF(root)==-2){
                if(getBF(root->rchild)==-1){//RR形
                    L(root);
                }
                else if(getBF(root->rchild)==1){//RL形
                    R(root->rchild);
                    L(root);
                }
            }
        }

}//else写到了if里面

int isfirst=1;
void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    vec.push_back(NULL);
    vec.push_back(root);
    while(!q.empty()){
        node* front=q.front();
        q.pop();
        if(isfirst){
            printf("%d",front->data);
            isfirst=0;
        }else printf(" %d",front->data);
        if(front->lchild!=NULL) {q.push(front->lchild);vec.push_back(front->lchild);}
        if(front->rchild!=NULL) {q.push(front->rchild);vec.push_back(front->rchild);}
    }
}

bool juge(node* root){
    for(int i=1;i<=n/2;i++){
        node* root=vec[i];
        if(i*2<=n&&root->lchild!=vec[i*2]) return false;
        if(i*2+1<=n&&root->rchild!=vec[i*2+1]) return false;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    root==NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        insert(root,x);
    }
    levelOrder(root);
    printf("\n%s",juge(root)==true?"YES":"NO");
    return 0;
}
