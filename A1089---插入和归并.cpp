#include<stdio.h>
#include<algorithm>
using namespace std;

const int N = 110;
int n,origin[N],tempOri[N],changed[N];

bool Equal(int a[],int b[]){
    for(int i=0;i<n;i++)
        if(a[i]!=b[i]) return false;
    return true;
}
void printSeq(int a[]){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        if(i<n-1) printf(" ");
    }
}

bool InsertSort(){
    bool flag = false;//记录是否在数组中间步骤与changed数组相同
    for(int i=1;i<n;i++){
        if(i!=1&&Equal(tempOri,changed)) flag=true;//中间步骤与changed相同且不是初始序列
        //插入部分
        int k = tempOri[i],j=i;
        while(j>0&&tempOri[j-1]>k){
            tempOri[j] = tempOri[j-1];
            j--;
        }
        tempOri[j] = k;
        if(flag==true) return true;
    }
    return false;
}

void mergeSort(){
    bool flag =false;
    for(int step=2;step/2<=n;step*=2){
        if(step!=2&&Equal(tempOri,changed)) flag = true;
        for(int i=0;i<n;i+=step){
            sort(tempOri+i,tempOri+min(i+step,n));
        }
        if(flag==true){
            printSeq(tempOri);
            return;
        }
    }
}



int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&origin[i]);
        tempOri[i] = origin[i];
    }
    for(int i=0;i<n;i++)
        scanf("%d",&changed[i]);
    if(InsertSort()){
        printf("Insertion Sort\n");
        printSeq(tempOri);
    }else {
        printf("Merge Sort\n");
        for(int i=0;i<n;i++) tempOri[i] = origin[i];//还原
        mergeSort();
    }
    return 0;
}
//初始序列不参与比较
