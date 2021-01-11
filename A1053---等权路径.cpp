#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int N=110;
struct node{
    int weight;
    vector<int> child;
}tree[N];

int n,m,s,pathNum=0;
vector<int> temp,path[N];

void DFS(int root,int w){
    temp.push_back(tree[root].weight);
    w+=tree[root].weight;
    if(w<s){
        for(int i=0;i<tree[root].child.size();i++){
            DFS(tree[root].child[i],w);
        }
    }else if(w==s&&tree[root].child.empty()){
        path[pathNum++]=temp;
    }
    temp.pop_back();
}

bool cmp(vector<int> a,vector<int> b){
    int len1=a.size(),len2=b.size();
    for(int i=0;i<len1&&i<len2;i++){
        if(a[i]!=b[i]) return a[i]>b[i];
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<n;i++)
        scanf("%d",&tree[i].weight);
    int id,k,child;
    for(int i=0;i<m;i++){
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&child);
            tree[id].child.push_back(child);
        }
    }
    DFS(0,0);
    sort(path,path+pathNum,cmp);
    for(int i=0;i<pathNum;i++){
        int len=path[i].size();
        for(int j=0;j<len;j++){
            printf("%d",path[i][j]);
            if(j<len-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
