
//����ʱ��ʹ��sort����
//ð������
void BubbleSort(int a[],int n){
    int flag,temp;
    for(int i=0;i<n-1;i++){
        flag=false;        //�����Ƿ�������
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

//ѡ������
void SelectSort(int a[],int n){
    int k,temp;
    for(int i=0;i<n-1;i++){  //һ������n-1��
        k=i;
        for(int j=i+1;j<n;j++)
            if(a[k]>a[j]) k=j
        temp = a[i];
        a[i] = a[k];
        a[k] = temp
    }
}

//ֱ�Ӳ�������
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
