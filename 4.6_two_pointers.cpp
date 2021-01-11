//利用问题本身与序列的特性，使用两个下标i,j对序列进行扫描
//（可以同向，也可以反向），以较低的复杂度解决问题

//归并排序

//递归实现
const int maxn=100;
//将数组A的[L1,R1] [L2,R2](L2=R1+1)的区间合并为一个区间
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
        A[L1+i]=temp[i];//将合并后的序列赋值回A
}

void mergeSort(int A[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);
    }
}

/*非递归
1.令step初值为2
2.每step个元素作为一组进行排序
3.在令step*2,重复上面操作,直到step/2超过元素个数n
*/
void mergeSort(int A[]){
    //step为组内元素个数，step/2为左区间元素个数，注意等号可以不取
    for(int step=2;step/2<=n;step*=2){
        for(int i=1;i<=n;i+=step){//对每一组
            int mid=i+step/2-1;//左区间元素个数为step/2;
            if(mid+1<=n){//右区间存在元素则合并
                merge(A,i,mid,mid+1,min(i+step-1,n));
            }
        /*如果下标是0
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

//如果题目中要求给出归并排序每一堂结束时的序列，可以使用sort代替merge函数
void mergeSort(int A[]){
    for(int step=2;step/2<=n;step*=2){
        for(int i=1;i<=n;i+=step){
            sort(A+i,A+min(i+step,n+1));//左闭右开
        }
        //此处可以输出一趟归并结束序列
    }
}

/*快速排序
1.tow_pointer思想,left=1,right=n;
2.A[right]>temp,不断左移,否则swap(A[left],A[right])
3.A[left]<=temp,不断右移，否则swap(A[left],A[right])
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
/*总是选择A[left]作为主元不好，应随机选择
1.srand((unsigned)time(NULL));//<time.h><stdlib.h>
2.产生区间[a,b]的随机数 rand()%5+3,[3,7];  不超过RAND_MAX=32767
3.更大区间随机数 (int)(round(1.0*rand()/RAND_MAX*(b-a+1))+a)
*/
int randPartion(int A[],int left,int right){
    int p=(round(1.0*rand()/RAND_MAX*(right-left))+left);
    swap(A[p],A[left]);
    //代码略...
}

