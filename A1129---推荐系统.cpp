#include<cstdio>
#include<set>
using namespace std;

const int N=50010;

int book[N]={0};//���item���ֵĴ������ò���set����
struct node{
    int value,cnt;//��ţ�����
    bool operator < (const node &a) const{
        return (cnt!=a.cnt)?cnt>a.cnt:value<a.value;
    }
};

int main(){
    int n,k,num;
    scanf("%d%d",&n,&k);
    set<node> s;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        if(i!=0){
            printf("%d:",num);
            int tempCnt=0;
            for(set<node>::iterator it=s.begin();tempCnt<k&&it!=s.end();it++){
                printf(" %d",it->value);//���������ʽṹ����Ķ����൱��ָ��ȥ����
                tempCnt++;
            }
            printf("\n");
        }
        set<node>::iterator it = s.find(node{num,book[num]});
        if(it!=s.end()) s.erase(it);
        book[num]++;
        s.insert(node{num,book[num]});
    }
    return 0;
}
/*
1.Ƶ��Խ��Խ���Ƽ�
2.��ͬ��idԽСԽ���Ƽ�
3.map<item,time> ���ܰ��մ���time���򣬶�����Ŀ��Ҫ����������ϸ��ӣ���Ҫ����
  �ṹ�壬����ýṹ������ֻ������һ����������������������������ʹ��set<node>
  ����<�����
4.ÿ��Ѱ��set�е�ǰֵΪnum�ʹ���Ϊbook[num]���Ǹ�ֵ������ҵ��˾Ͱ����Ƴ���
���ҵ�˵��������Ѿ����ֹ�����cnt�Ѿ������������Ƴ����ɡ���
Ȼ��book[num]+1���ڽ�node(num, book[num])���뵽set�У�
*/
