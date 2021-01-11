#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int N=10010;

struct node{
    int Mestae;
    int Area;
}Property[N];

struct family{//按照这个排序
    int root;
    int m,valid;
    int Totalsets,Totalarea;
}Fam[N];

struct Res{
    int num,id;
    double Set,area;
};
int vis[N];//由于序号不连续，需要记录哪些序号出现过
vector<int> R;
vector<Res> Result;
int father[N];

bool cmp(Res a,Res b){
    if(a.area!=b.area) return a.area>b.area;
    else return a.id<b.id;
}
int findFather(int a){
    int root=a;
    while(root!=father[root]) root=father[root];

    while(a!=father[a]){
        int z=a;
        father[z]=root;
        a=father[a];
    }

    return root;
}

void Union(int a,int b){
    int faA=findFather(a);
    int faB=findFather(b);
    if(faA<faB) father[faB]=faA;
    else father[faA]=faB;
}

void Init(){

    for(int i=0;i<N;i++){
        father[i]=i;
    }

    int n;
    scanf("%d",&n);
    int id,fid,mid,k,child;

    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&id,&fid,&mid,&k);
        vis[id]=1;
        if(fid!=-1){
            vis[fid]=1;
            Union(id,fid);
        }
        if(mid!=-1){
            vis[mid]=1;
            Union(id,mid);
        }

        for(int j=0;j<k;j++){
            scanf("%d",&child);
            vis[child]=1;
            Union(id,child);
        }
        scanf("%d%d",&Property[id].Mestae,&Property[id].Area);
    }

}

void Op(){

    for(int i=0;i<10000;i++){
        if(vis[i]){
            int k=findFather(i);
            if(Fam[k].valid==0){//把father们存到R里面
                Fam[k].valid=1;
                Fam[k].root=i;
                R.push_back(k);
            }
            Fam[k].m++;
            Fam[k].Totalarea+=Property[i].Area;
            Fam[k].Totalsets+=Property[i].Mestae;
        }
    }

    Res temp;
    for(int i=0;i<R.size();i++){
        temp.id=Fam[R[i]].root;
        temp.num=Fam[R[i]].m;
        temp.Set=(1.0*Fam[R[i]].Totalsets)/(1.0*temp.num);
        temp.area=(1.0*Fam[R[i]].Totalarea)/(1.0*temp.num);
        Result.push_back(temp);
    }

    sort(Result.begin(),Result.end(),cmp);
}

void Print(){
    Res temp;
    printf("%d\n",Result.size());
    for(int i=0;i<Result.size();i++){
        temp=Result[i];
        printf("%04d %d %.3f %.3f\n",temp.id,temp.num,temp.Set,temp.area);
    }
}
int main(){
    Init();
    Op();
    Print();
    return 0;
}

