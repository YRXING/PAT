#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct Node{//1.����
    int adress;
    int key;
    int next;
    bool flag;//����Ƿ���������
}node[maxn];

bool cmp(Node a,Node b){
    if(a.flag==false||b.flag==false)
        return a.flag>b.flag;
    else return a.key<b.key;
}

int main(){
    int n,head;
    scanf("%d%d",&n,&head);
    for(int i=0;i<maxn;i++)//2.��ʼ��
        node[i].flag=false;
    for(int i=0;i<n;i++){
        int adress;
        scanf("%d",&adress);
        scanf("%d%d",&node[adress].key,&node[adress].next);
        node[adress].adress=adress;
    }
    int count=0,p=head;
    while(p!=-1){//3.ö�٣���flag��ǣ�ͬʱ����
        node[p].flag=true;
        p=node[p].next;
        count++;
    }
    if(count==0) printf("0 -1");//����
    else{
        sort(node,node+maxn,cmp);//4.����ɸѡ��Ч���
        printf("%d %05d\n",count,node[0].adress);//5.���
        for(int i=0;i<count;i++){
            if(i<count-1)
                printf("%05d %d %05d\n",node[i].adress,node[i].key,node[i+1].adress);
            else
                printf("%05d %d -1\n",node[i].adress,node[i].key);
        }
    }
    return 0;
}
/*
1.��Ŀ���ܻ�����Ч��㣬��������Ŀ�������׵�ַ��ʼ��������
2.�������滹��ȫ������Ч���������ʱ��Ҫ������Ч���ĸ������������0-1��*/
