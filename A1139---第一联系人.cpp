#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int N=10000;
map<int,bool> arr;//关系数组,用int会超时
vector<int> v[N];//所有人的同性朋友
struct node{//结果存到结点里，方便排序
    int a,b;
    node(int _a,int _b):a(_a),b(_b){}
};
vector<node> ans;
bool cmp(node x,node y){
    if(x.a!=y.a) return x.a<y.a;
    else return y.b>x.b;
}

int main(){
    int n,m,k;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        if(a.length()==b.length()){//存储同性朋友
            v[abs(atoi(a.c_str()))].push_back(abs(atoi(b.c_str())));
            v[abs(atoi(b.c_str()))].push_back(abs(atoi(a.c_str())));
        }
        arr[abs(atoi(a.c_str())) * 10000 + abs(atoi(b.c_str()))] = arr[abs(atoi(b.c_str())) * 10000 + abs(atoi(a.c_str()))] = true;
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int c,d;
        cin>>c>>d;
        ans.clear();
        for(int j=0;j<v[abs(c)].size();j++)//列举c,d的同性朋友，判断每一对是否是朋友
        for(int k=0;k<v[abs(d)].size();k++){
            if(v[abs(c)][j]==abs(d)||abs(c)==v[abs(d)][k]) continue;
            if(arr[v[abs(c)][j]*10000+v[abs(d)][k]]==true)
                ans.push_back(node(v[abs(c)][j],v[abs(d)][k]));
        }
        sort(ans.begin(),ans.end(),cmp);
        printf("%d\n",ans.size());
        for(int j=0;j<ans.size();j++)
            printf("%04d %04d\n",ans[j].a,ans[j].b);
    }

    return 0;
}

/*
1.用数组arr标记两个人是否是朋友（邻接矩阵），用v标记所有人的同性朋友（邻接表）
2.对于A,B，先找到A的所有同性朋友C，再找到B的所有同性朋友D，C,D是朋友则输出
3.A,B的同性朋友不包括A和B
4.如果用int接受一对朋友，-0000和0000来说都是0，无法得知这个人的性别，所以要用字符串
5.结果排序
*/
