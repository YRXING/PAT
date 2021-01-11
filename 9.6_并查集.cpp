//ͬһ������ֻ����һ�����ڵ㣬�ҽ�����Ϊ�������ϱ�ʶ

//��ʼ��
void init(){
    for(int i=0;i<n;i++){
        father[i]=i;
    }
}

//���ң����������Ѱ�Ҹ��ڵ�Ĺ���
int findFather(int x){
    while(x!=father[x]){
        x = father[x];
    }
    return x;
}

//�ϲ�
void Union(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA!=faB) father[faA] = faB;
}

//·��ѹ��
//�Ѳ�ѯ�ڵ�·���ϵ����н��ĸ��׶�ָ�����㣬����ʱ��Ͳ��û���
//1.Ѱ�Ҹ��ڵ�
//2.���´�x��һ�飬���ڵ��޸�Ϊ���ڵ�
int findFather(int x){
    int a = x;
    while(x!=father[x]) x = father[x];
    while(a!=father[a]){
        int z = a;
        father[z] = x;
        a = father[a];
    }
    return x;
}


