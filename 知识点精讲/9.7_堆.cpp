//堆是一颗完全二叉树,堆一般用于优先队列的实现（默认大顶堆）
const int maxn = 100;
int heap[maxn],n=10;

//low为欲调整结点的数组下标，high一般为堆的最后一个元素的下标
void downAdjust(int low,int high){
    int i = low,j=i*2;//i为欲调整结点，j为左孩子
    while(j<=high){
        if(j+1<=high&&heap[j]<heap[j+1])
            j=j+1;//右孩子存在并且右孩子大j存储右孩子下标
        if(heap[j]>heap[i]){
            swap(heap[j],heap[i]);
            i = j;
            j = i*2;
        }else break;//孩子权值均比i小，调整结束
    }
}
//[1,n/2]都是非叶子结点
void createHeap(){//要倒着枚举向下调整所有非叶子结点
    for(int i=n/2;i>=1;i--)
        downAdjust(i,n);
}

void deleteTop(){
    heap[1] = heap[n--];
    downAdjust(1,n);
}

//low一般设置为1，high表示欲调整结点
void upAdjust(int low,int high){
    int i=high,j=i/2;//i为欲调整结点,j为父亲
    while(j>=low){
        if(heap[j]<heap[i]){
            swap(heap[j],heap[i]);
            i = j;
            j = i/2;
        }else break;
    }
}

void insert(int x){
    heap[++n] = x;
    upAdjust(1,n);
}

//堆排序
void heapSort(){
    createHeap();
    for(int i=n,i>1;i--){//倒着枚举，直到堆顶只有一个元素
        swap(heap[i],heap[1]);
        downAdjust(1,i-1);//调整堆顶
    }
}




