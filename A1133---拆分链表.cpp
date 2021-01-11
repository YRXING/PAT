#include<cstdio>
#include<algorithm>
using namespace std;

const int N=100010;
const int INF=1000000000;
struct node{
    int adress;
    int data;
    int next;
    int order,type,valid;
}List[N];
int first,n,k;
bool cmp(node a,node b){
    if(a.valid!=b.valid) return a.valid>b.valid;
    else if(a.type!=b.type) return a.type<b.type;
    else return a.order<b.order;
}

void init(){
    for(int i=0;i<N;i++){
        List[i].valid=-1;
    }
}

int main(){
    init();
    scanf("%d%d%d",&first,&n,&k);

    for(int i=0;i<n;i++){
        int ad;
        scanf("%d",&ad);
        List[ad].adress=ad;
        scanf("%d%d",&List[ad].data,&List[ad].next);
        if(List[ad].data<0) List[ad].type=1;
        else if(List[ad].data<=k) List[ad].type=2;
        else List[ad].type=3;
        List[ad].valid=1;
    }

    int count=0,p=first;
    while(p!=-1){
        List[p].order=count++;
        p=List[p].next;
    }

    sort(List,List+N,cmp);
    for(int i=0;i<count;i++){
            printf("%05d %d ",List[i].adress,List[i].data);
            if(i<count-1)
                printf("%05d\n",List[i+1].adress);
            else printf("-1\n");

    }
    return 0;
}


/*
1.分类别排序试题，可在结构体里面加一个type字段，读入数据时进行赋值
2.此题还可以三次遍历静态链表，每次筛选出来的Node存入vector里
3.倒数第二测试点错误
*/

//#include<cstdio>
//#include<algorithm>
//using namespace std;
//#define maxn 100010
//
//struct Node{
//    int id,next,seq,data,type;
//    int vivid;
//}node[maxn];
//
//int seq=0,st,N,K;
//
//bool cmp(Node a,Node b){
//    if(a.vivid!=b.vivid){
//        return a.vivid>b.vivid;
//    }else if(a.type!=b.type){
//        return a.type>b.type;
//    }else{
//        return a.seq<b.seq;
//    }
//}
//
//void Init(){
//    int id,data,next;
//    scanf("%d%d%d",&st,&N,&K);
//    while(N--){
//        scanf("%d%d%d",&id,&data,&next);
//        node[id].id=id;
//        node[id].data=data;
//        node[id].next=next;
//        if(data<0){
//            node[id].type=3;
//        }else if(data<=K){
//            node[id].type=2;
//        }else{
//            node[id].type=1;
//        }
//    }
//}
//
//void Op(){
//    while(st!=-1){
//        node[st].seq=seq++;
//        node[st].vivid=1;
//        st=node[st].next;
//    }
//    sort(node,node+maxn,cmp);
//}
//
//void Print(){
//    int i;
//    printf("%05d %d ",node[0].id,node[0].data);
//    for(i=1;i<seq;i++){
//        printf("%05d\n%05d %d ",node[i].id,node[i].id,node[i].data);
//    }
//    printf("-1\n");
//}
//
//int main(){
//    Init();
//    Op();
//    Print();
//    return 0;
//}

