/*给出一个非负整数序列A，0<=A[i]<=10^5,元素个数N，在有可能随时添加或删除的情况下，
实时查询序列元素的第K大
如果在查询过程中元素可能发生改变，称在线查询，否则称离线查询

分块：
对一个有N个元素的有序序列来说，除最后一块外，其余每块有[N^1/2]（向下取整），块数为[N^1/2]（向上取整）
*/
int table[100001];//table[x]表示x当前存在的个数,分成317块，每块316个元素
int block[317];//block[i]表示第i块中存在元素的个数
//增加一个元素x，block[x/316]++;table[x]++;
//删除一个元素x，block[x/316]--;table[x]--;
/*
1.从小到大枚举块号，累加的到i-1块中存在的元素个数,如果加入i号块，元素总个数能达到K，
说明x在i号块中
2.从小到大遍历该块中的每个元素（i号块第一个元素为i*316）,利用table数组累加个数，达到K为止


/*lowbit(x)就是去x的二进制最右边的1和它右边所有的0；
也可以理解为能整除x的最大2的幂次。
树状数组BIT
#define lowbit(x) ((x)&(-x))
// C++ Version
int lowbit(int x) {
  // x 的二进制表示中，最低位的 1 的位置。
  // lowbit(0b10110000) == 0b00010000
  //          ~~~^~~~~
  // lowbit(0b11100100) == 0b00000100
  //          ~~~~~^~~
  return x & -x;
}

<1>给出一个整数序列A，元素个数N，查询K次，每次查询给出一个正整数x，求前x个整数之和
开一个sum数组，sum[i]表示前i个整数之和，输出sum[x]即可
<2>查询过程中随时给第x个数加上一个整数v，输出前x个整数之和
树状数组是个和sum数组类似的数组，存放的不是前i个数之和，而是在i号位之前（含i）lowbit(i)个整数之和
这样更新一个数据的时候，树状数组比前缀和数组具有更小的更新代价，当然要失去一点查询代价，适合频繁更新数据的在线查询前n个数之和的场景
c[i]的覆盖长度是lowbit(i)，序列A存储元素的时候下标必须从1开始！！！！
C[x]=A[x-lowbit(x)+1]+...+A[x] // 比如C[6] = A[6] + A[5], lowbit(6) = 2
SUM(1,x)=SUM(1,x-lowbit(x))+C[x]
*/
int getSum(int x){//返回前x个数的和
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i)){
        sum+=c[i];
    }
    return sum;
}

getSum(y)-getSum(x-1);//[x,y]内的数之和

//给A[x]加上v，如何更新C数组
//让x不断加上lowbit(x),让每步的C[x]机上v，知道x超过给定的数据范围为止
void update(int x,int v){//第x个数加v
    for(int i=x;i<=N;i+=lowbit(i)){
        c[i]+=v;
    }
}

/*
<3> 给定一个N个正整数序列A，对序列中的每一个数，求出序列中它左边比它小的数的个数
*/
const int maxn=100010;
#define lowbit(i) ((i)&(-i))
int c[maxn];

void update(int x,int v){
    for(int i=x;i<maxn;i+=lowbit(x))
        c[i]+=v;
}
int getSum(int x){
    int sum=0;
    for(int i=x;i>0;i-=lowbit(x))
        sum+=c[i];
    return sum;
}
int main(){
    int n,x;
    scanf("%d",&n);
    memset(c,0,sizeof(c));//树状数组初始为0
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        update(x,1);//相当于求A[x]=1的前缀和
        printf("%d\n",getSum(x-1));
    }
    return 0;
}


//统计元素左边比元素大的数等价于计算hash[x+1]+...+hash[N]=getSum(N)-getSum(x);
//离散化到1-N
//即：如果序列跨度比较大，或者包含负数的时候，无法用hash[x]=1来简单表示某个数是否存在时，需要离散化存储
//就是把序列的value通过排序后，转变为1-N。其中N为序列的大小。
//比如序列：-3 100000 26 -99999999
//离散化后：2    4     3     1
struct node{
    int val;//序列元素的值
    int pos;//原始序号
}temp[maxn];
int A[maxn];//离散化后的原始数组,相当于名次

bool cmp(node a,node b){
    return a.val<b.val;
}

for(int i=0;i<n;i++){
    scanf("%d",&temp[i].val);
    temp[i].pos=i;
}

sort(temp,temp+n,cmp);

for(int i=0;i<n;i++){
    if(i==0||temp[i].val!=temp[i-1].val)
        A[temp[i].pos]=i+1;
    else A[temp[i].pos]=A[temp[i-1].pos]
}

for(int i=0;i<n;i++){
    update(A[i],1);
    printf("%d\n",getSum(A[i]-1));
}


//求第K大，即求最小的i使得hash[1]+...+hash[i]>=K
//如果用树状数组来解决hash数组求和问题等价于“getSum(i)>=K”,使用二分思想
int findKthElement(int K){
    int l=1,r=MAXN,mid;
    while(l<r){
        mid=(l+r)/2;
        if(getSum(mid)>=K) r=mid;
        else l = mid+1;
    }
    return l;
}


//如果是二维
void update(int x,int y,int v){//（x,y）位置上加v
    for(int i=x;i<maxn;i+=lowbit(i))
        for(int j=y;j<maxn;j+=lowbit(j))
            c[i][j]+=v;
}
int getSum(int x,int y){//返回从（1,1）到（x,y）的子矩阵元素之和
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
        sum+=c[i][j];
    return sum;
}


