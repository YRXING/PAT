//ֻҪ������е����ԣ������ö���˼�����

//��������Ϊ����ұ�[left,right],����ĳ�ֵΪ[0,n-1]
//���е���
int binarySearch(int A[],int left,int right,int x){
    int mid;
    while(left<=right){  //left > right ��û�취�γɱ�������
        mid = (left+right)/2;//������� ������ mid = left+(right-left)/2 ����
        if(A[mid]==x) return mid;
        else if(A[mid]>x) right = mid-1;
        else left = mid+1;
    }
    return -1;
}

//���ص�һ�����ڵ���x��Ԫ��λ��[left,right]
int lower_bound(int A[],int left,int right,int x){
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if(A[mid]>=x) right = mid;
        else  left = mid +1;
    }
    return left;
}

//���ص�һ������x��Ԫ��λ��,[left,right]
int upper_bound(int A[],int left,int right ,int x){
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if(A[mid]>x) right = mid;
        else left = mid +1;
    }
    return left;
}

//��һ������ĳ����Ԫ�ص�λ��,(left,right]
int solve(int left,int right){
    int mid;
    while(left+1<right){
        mid = (left+right)/2;
        if(��������) right = mid;
        else left = mid+1;
    }
    return right;
}

//ľ���и�����:
//����N��ľ�������Ⱦ���֪����ϣ��ͨ���и��������õ�����K�γ�����ȵ�ľ��
//����Щ������ȵ�ľ������L����ж೤��
//LԽ����KԽ�٣����ö���.

