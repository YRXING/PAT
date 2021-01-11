//�������Ȿ�������е����ԣ�ʹ�������±�i,j�����н���ɨ��
//������ͬ��Ҳ���Է��򣩣��Խϵ͵ĸ��ӶȽ������

//�鲢����

//�ݹ�ʵ��
const int maxn=100;
//������A��[L1,R1] [L2,R2](L2=R1+1)������ϲ�Ϊһ������
void merge(int A[],int L1,int R1,int L2,int R2){
    int i=L1,j=L2;
    int temp[maxn],index=0;
    while(i<=R1&&j<=R2){
        if(A[i]<=A[j]) temp[index++]=A[i++];
        else temp[index++]=A[j++];
    }
    while(i<=R1) temp[index++]=A[i++];
    while(j<=R2) temp[index++]=A[j++];
    for(int i=0;i<index;i++)
        A[L1+i]=temp[i];//���ϲ�������и�ֵ��A
}

void mergeSort(int A[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);
    }
}

/*�ǵݹ�
1.��step��ֵΪ2
2.ÿstep��Ԫ����Ϊһ���������
3.����step*2,�ظ��������,ֱ��step/2����Ԫ�ظ���n
*/
void mergeSort(int A[]){
    //stepΪ����Ԫ�ظ�����step/2Ϊ������Ԫ�ظ�����ע��Ⱥſ��Բ�ȡ
    for(int step=2;step/2<=n;step*=2){
        for(int i=1;i<=n;i+=step){//��ÿһ��
            int mid=i+step/2-1;//������Ԫ�ظ���Ϊstep/2;
            if(mid+1<=n){//���������Ԫ����ϲ�
                merge(A,i,mid,mid+1,min(i+step-1,n));
            }
        /*����±���0
        for(int i=0;i<n;i+=step){
            int mid=i+step/2-1;
            if(mid+1<n){
                merge(A,i,mid,mid+1,min(i+step-1,n-1));
            }
        }
        */
        }
    }
}

//�����Ŀ��Ҫ������鲢����ÿһ�ý���ʱ�����У�����ʹ��sort����merge����
void mergeSort(int A[]){
    for(int step=2;step/2<=n;step*=2){
        for(int i=1;i<=n;i+=step){
            sort(A+i,A+min(i+step,n+1));//����ҿ�
        }
        //�˴��������һ�˹鲢��������
    }
}

/*��������
1.tow_pointer˼��,left=1,right=n;
2.A[right]>temp,��������,����swap(A[left],A[right])
3.A[left]<=temp,�������ƣ�����swap(A[left],A[right])
*/
int Partition(int A[],int left,int right){
    int temp=A[left];
    while(left<right){
        while(left<right&&A[rigjt]>temp) right--;
        A[left]=A[right];
        while(left<right&&A[left]<=temp) left++;
        A[right]=A[left];
    }
    A[left]=temp;
    return left;
}

void quickSort(int A[],int left,int right){
    if(left<right){
        int pos=Partition(A,left,right);
        quickSort(A,left,pos-1);
        quickSort(A,pos+1,right);
    }
}
/*����ѡ��A[left]��Ϊ��Ԫ���ã�Ӧ���ѡ��
1.srand((unsigned)time(NULL));//<time.h><stdlib.h>
2.��������[a,b]������� rand()%5+3,[3,7];  ������RAND_MAX=32767
3.������������� (int)(round(1.0*rand()/RAND_MAX*(b-a+1))+a)
*/
int randPartion(int A[],int left,int right){
    int p=(round(1.0*rand()/RAND_MAX*(right-left))+left);
    swap(A[p],A[left]);
    //������...
}

