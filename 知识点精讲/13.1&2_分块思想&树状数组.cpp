/*����һ���Ǹ���������A��0<=A[i]<=10^5,Ԫ�ظ���N�����п�����ʱ��ӻ�ɾ��������£�
ʵʱ��ѯ����Ԫ�صĵ�K��
����ڲ�ѯ������Ԫ�ؿ��ܷ����ı䣬�����߲�ѯ����������߲�ѯ

�ֿ飺
��һ����N��Ԫ�ص�����������˵�������һ���⣬����ÿ����[N^1/2]������ȡ����������Ϊ[N^1/2]������ȡ����
*/
int table[100001];//table[x]��ʾx��ǰ���ڵĸ���,�ֳ�317�飬ÿ��316��Ԫ��
int block[317];//block[i]��ʾ��i���д���Ԫ�صĸ���
//����һ��Ԫ��x��block[x/316]++;table[x]++;
//ɾ��һ��Ԫ��x��block[x/316]--;table[x]--;
/*
1.��С����ö�ٿ�ţ��ۼӵĵ�i-1���д��ڵ�Ԫ�ظ���,�������i�ſ飬Ԫ���ܸ����ܴﵽK��
˵��x��i�ſ���
2.��С��������ÿ��е�ÿ��Ԫ�أ�i�ſ��һ��Ԫ��Ϊi*316��,����table�����ۼӸ������ﵽKΪֹ


/*lowbit(x)����ȥx�Ķ��������ұߵ�1�����ұ����е�0��
Ҳ�������Ϊ������x�����2���ݴΡ�
��״����BIT
#define lowbit(x) ((x)&(-x))

<1>����һ����������A��Ԫ�ظ���N����ѯK�Σ�ÿ�β�ѯ����һ��������x����ǰx������֮��
��һ��sum���飬sum[i]��ʾǰi������֮�ͣ����sum[x]����
<2>��ѯ��������ʱ����x��������һ������v�����ǰx������֮��
��״�����Ǹ���sum�������Ƶ����飬��ŵĲ���ǰi����֮�ͣ�������i��λ֮ǰ����i��lowbit(i)������֮��
c[i]�ĸ��ǳ�����lowbit(i)���±�����1��ʼ��������
C[x]=A[x-lowbit(x)+1]+...+A[x]
SUM(1,x)=SUM(1,x-lowbit(x))+C[x]
*/
int getSum(int x){//����ǰx�����ĺ�
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i)){
        sum+=c[i];
    }
    return sum;
}

getSum(y)-getSum(x-1);//[x,y]�ڵ���֮��

//��A[x]����v����θ���C����
//��x���ϼ���lowbit(x),��ÿ����C[x]����v��֪��x�������������ݷ�ΧΪֹ
void update(int x,int v){//��x������v
    for(int i=x;i<+N;i+=lowbit(x)){
        c[i]+=v;
    }
}

/*
<3> ����һ��N������������A���������е�ÿһ�������������������߱���С�����ĸ���
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
    memset(c,0,sizeof(c));//��״�����ʼΪ0
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        update(x,1);
        printf("%d\n",getSum(x-1));
    }
    return 0;
}


//ͳ��Ԫ����߱�Ԫ�ش�����ȼ��ڼ���hash[x+1]+...+hash[N]=getSum(N)-getSum(x);
//��ɢ����1-N
struct node{
    int val;//����Ԫ�ص�ֵ
    int pos;//ԭʼ���
}temp[maxn];
int A[maxn];//��ɢ�����ԭʼ����,�൱������

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


//���K�󣬼�����С��iʹ��hash[1]+...+hash[i]>=K
//�������״���������hash�����������ȼ��ڡ�getSum(i)>=K��,ʹ�ö���˼��
int findKthElement(int K){
    int l=1,r=MAXN,mid;
    while(l<r){
        mid=(l+r)/2;
        if(getSum(mid)>=K) r=mid;
        else l = mid+1;
    }
    return l;
}


//����Ƕ�ά
void update(int x,int y,int v){//��x,y��λ���ϼ�v
    for(int i=x;i<maxn;i+=lowbit(i))
        for(int j=y;j<maxn;j+=lowbit(j))
            c[i][j]+=v;
}
int getSum(int x,int y){//���شӣ�1,1������x,y�����Ӿ���Ԫ��֮��
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
        sum+=c[i][j];
    return sum;
}


