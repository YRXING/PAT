
//考试时候使用sort函数
//冒泡排序
void BubbleSort(int a[],int n){
    int flag,temp;
    for(int i=0;i<n-1;i++){
        flag=false;        //本趟是否发生交换
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                flag = true;
            }
        }
        if(!flag) return;
    }
}

//选择排序
void SelectSort(int a[],int n){
    int k,temp;
    for(int i=0;i<n-1;i++){  //一共进行n-1趟
        k=i;
        for(int j=i+1;j<n;j++)
            if(a[k]>a[j]) k=j
        temp = a[i];
        a[i] = a[k];
        a[k] = temp
    }
}

//直接插入排序
void InsertSort(int a[],int n){
    int temp,i,j;
    for(i=1;i<n;i++){
        if(a[i]<a[i-1]){
            temp = a[i];
            for(j=i-1;temp<a[j];j--)
                    a[j+1]=a[j];
            a[j+1]=temp
        }
    }
}
