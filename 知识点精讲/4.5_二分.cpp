//只要问题具有单调性，都可用二分思想求解

//二分区间为左闭右闭[left,right],传入的初值为[0,n-1]
//序列递增
int binarySearch(int A[],int left,int right,int x){
    int mid;
    while(left<=right){  //left > right 就没办法形成闭区间了
        mid = (left+right)/2;//避免溢出 可以用 mid = left+(right-left)/2 代替
        if(A[mid]==x) return mid;
        else if(A[mid]>x) right = mid-1;
        else left = mid+1;
    }
    return -1;
}

//返回第一个大于等于x的元素位置[left,right]
int lower_bound(int A[],int left,int right,int x){
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if(A[mid]>=x) right = mid;
        else  left = mid +1;
    }
    return left;
}

//返回第一个大于x的元素位置,[left,right]
int upper_bound(int A[],int left,int right ,int x){
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if(A[mid]>x) right = mid;
        else left = mid +1;
    }
    return left;
}

//第一个满足某条件元素的位置,(left,right]
int solve(int left,int right){
    int mid;
    while(left+1<right){
        mid = (left+right)/2;
        if(条件成立) right = mid;
        else left = mid+1;
    }
    return right;
}

//木棒切割问题:
//给出N根木棒，长度均已知，现希望通过切割他们来得到至少K段长度相等的木棒
//问这些长度相等的木棒长度L最长能有多长。
//L越长，K越少，可用二分.

