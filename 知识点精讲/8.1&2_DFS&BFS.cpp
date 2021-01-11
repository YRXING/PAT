/*DFS
1.�������������һ��ö����������·���Ա��������������������
2.�ݹ��еĵݹ�ʽ���ǲ���ڣ��ݹ�߽��������ͬ��
  ʹ�õݹ���Ժܺõ�ʵ����������������䱾�ʾ���ջ
*/
//�������⣺
//��n����Ʒ������w[i],��ֵc[i]���ڲ�������������V��ǰ���£�������ֵ��1<=n<=20��
#include<stdio.h>
const int maxn=30;
int n,V,maxValue=0;
int w[maxn],c[maxn];
void DFS(int index,int sumW,int sumC){
    if(index==n){//�Ѿ���ɶ�n����Ʒ��ѡ������ͬ��
        if(sumW<=V&&sumC>maxValue) maxValue = sumC;
        return ;
    }
    //�����
    DFS(index+1,sumW,sumC)//��ѡ��index����Ʒ
    DFS(index+1,sumW+w[index],sumC+c[index]);//ѡ��index����Ʒ
}
//���Ӷ�O(2^n)

//ֻ�е�sunW<=Vʱ�Ž��������Լ���������ֵ(��֦)
void DFS(int index,int sumW,int sumC){
    if(index == n) return;
    DFS(index+1,sumW,sumC)//��ѡ��index����Ʒ
    if(sumW+w[index]<=V){
        if(sumC+c[index]>ans){
            ans = sumc+c[index];//��������ֵmaxValue
        }
        DFS(index+1,sumW+w[index],sumC+c[index]);//ѡ��index����Ʒ
    }
}

/*���Խ�������⣺
1.����һ�����У�ö��������е�����������
2.ö�ٴ�N��������ѡ��K���������з���
*/

//����N��������ѡ��K������ʹ����K����֮��ǡ�õ���X������ж��ַ�����ѡ��������Ԫ��ƽ��������һ��
int n,k,x,maxSumSqu=-1,A[maxn];
//temp�����ʱ������ans�����󷽰�
vector<int >temp,ans;
void DFS(int index,int nowK,int sum,int sumSqu){
    if(nowK==k&&sum==x){
        if(sumSqu>maxSumSqu){
            maxSumSqu=sumSqu;
            ans=temp;
        }
        return;
    }
    if(index==n||nowK>k||sum>x) return;
    temp.push_back(A[index]);//ѡindex����
    DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
    temp.pop_back();
    DFS(index+1,nowK,sum,sumSqu);//��ѡindex����
}

//BFS
//BFS��ÿ���ڵ�ֻ���һ��,STL�е�push��һ������
//��������Ҫ�޸�Ԫ�أ�������Ӧ���Ԫ�صı��(��������������±�)
void BFS(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        //ȡ������Ԫ��top;
        //���ʶ���Ԫ��top��
        //������Ԫ�س���;
        //��top����һ��ڵ���δ����ӵĽ��ȫ����ӣ������������
    }
}

//����ͨ��
#include<cstdio>
#include<queue>
using namespace std;

const int maxn=100;
struct node{
    int x,y;
}Node;

int m,n;
int matrix[maxn][maxn];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
bool inq[maxn][maxn]={false};

bool juge(int x,int y){//�ж�(x,y)�Ƿ���Ҫ����
    //Խ�緵��false
    if(x>=n||x<0||y>=m||y<0) return false;
    if(matrix[x][y]==0||inq[x][y]==true) return false;
    return true;
}

void BFS(int x,int y){//BFS����x,y���ڵĿ�
    queue<node> Q;
    Node.x=x;Node.y=y;
    Q.push(Node);
    inq[x][y]=true;
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int newX = top.x+X[i];
            int newY = top.x+Y[i];
            if(juge(newX,newY)){
                Node.x=x,Node.y;
                Q.push(Node);
                inq[newX][newY]=true;
            }
        }
    }
}
