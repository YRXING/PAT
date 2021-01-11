//静态链表
/*结点的地址是比较小的整数，（例如5位数的地址），更多的使用静态链表
实现原理是hash，由于结点的访问非常方便，因此不需要头结点。
*/
struct Node{
    typename data;
    int next;
}node[size];
//使用静态链表时候，尽量不要把结构体类型名和结构体变量名取相同的名字

/*通用的解题步骤
1.定义静态链表
struct Node{
    int adress;
    typename data;
    int next;
    xxx;//结点的某个性质，不同题目不同设置
}
2.程序开始时，对静态链表初始化。
for(int i=0;i<maxn;i++){
    node[i].xxx=0;
}
3.题目一般都会给出一条链表的首节点地址，那么我们 就可以根据这个地址来遍历得到整条链表
  同时可以对xxx进行标记，并且对有效结点的个数进行计数
  int p=begin,count=0;
  while(p!=-1){
    xxx=1;
    count++;
    p=node[p]->next;
  }
4.由于直接采用地址hash，会使得数组下标不连续，而很多题目给出的结点并不都是有效结点，
  为了能够可控地访问有效结点，一般都需要用对数组进行排序把有效结点移到数组左端。
  这就需要xxx来帮忙
bool cmp(Node a,Node b){
    if(a.xxx==-1||b.xxx==-1){
        至少一个是无效结点
        return a.xxx>b.xxx
    }
    else{
        //第二级排序
    }
}
*/
