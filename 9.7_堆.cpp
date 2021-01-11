//����һ����ȫ������,��һ���������ȶ��е�ʵ�֣�Ĭ�ϴ󶥶ѣ�
const int maxn = 100;
int heap[maxn],n=10;

//lowΪ���������������±꣬highһ��Ϊ�ѵ����һ��Ԫ�ص��±�
void downAdjust(int low,int high){
    int i = low,j=i*2;//iΪ��������㣬jΪ����
    while(j<=high){
        if(j+1<=high&&heap[j]<heap[j+1])
            j=j+1;//�Һ��Ӵ��ڲ����Һ��Ӵ�j�洢�Һ����±�
        if(heap[j]>heap[i]){
            swap(heap[j],heap[i]);
            i = j;
            j = i*2;
        }else break;//����Ȩֵ����iС����������
    }
}
//[1,n/2]���Ƿ�Ҷ�ӽ��
void createHeap(){//Ҫ����ö�����µ������з�Ҷ�ӽ��
    for(int i=n/2;i>=1;i--)
        downAdjust(i,n);
}

void deleteTop(){
    heap[1] = heap[n--];
    downAdjust(1,n);
}

//lowһ������Ϊ1��high��ʾ���������
void upAdjust(int low,int high){
    int i=high,j=i/2;//iΪ���������,jΪ����
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

//������
void heapSort(){
    createHeap();
    for(int i=n,i>1;i--){//����ö�٣�ֱ���Ѷ�ֻ��һ��Ԫ��
        swap(heap[i],heap[1]);
        downAdjust(1,i-1);//�����Ѷ�
    }
}




