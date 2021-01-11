//同一个集合只存在一个根节点，且将其作为所属集合标识

//初始化
void init(){
    for(int i=0;i<n;i++){
        father[i]=i;
    }
}

//查找，即给定结点寻找根节点的过程
int findFather(int x){
    while(x!=father[x]){
        x = father[x];
    }
    return x;
}

//合并
void Union(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA!=faB) father[faA] = faB;
}

//路径压缩
//把查询节点路径上的所有结点的父亲都指向根结点，查找时候就不用回溯
//1.寻找根节点
//2.从新从x走一遍，父节点修改为根节点
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


