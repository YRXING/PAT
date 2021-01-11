#include<cstdio>
#include<set>
using namespace std;

const int N=50010;

int book[N]={0};//标记item出现的次数，好插入set里面
struct node{
    int value,cnt;//编号，次数
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
                printf(" %d",it->value);//迭代器访问结构体里的东西相当于指针去访问
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
1.频数越高越先推荐
2.相同，id越小越先推荐
3.map<item,time> 不能按照次数time排序，而且题目中要求的排序规则较复杂，需要定义
  结构体，如果用结构体数组只能排序一次输出，不能满足边输入边排序。因此使用set<node>
  重载<运算符
4.每次寻找set中当前值为num和次数为book[num]的那个值，如果找到了就把他移除，
（找到说明这个数已经出现过啦，cnt已经不对啦，先移除掉吧～）
然后将book[num]+1，在将node(num, book[num])插入到set中，
*/
