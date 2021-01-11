#include<map>
#include<string>
#include<iostream>
using namespace std;

const int maxn=2010;
map<int,string> intToString;//编号->姓名
map<string,int> stringToInt;//姓名->编号
map<string,int> Gang;

int G[maxn][maxn]={0},weight[maxn]={0};
int n,k,numPerson=0;
bool vis[maxn]={false};

int change(string str){
    if(stringToInt.find(str)!=stringToInt.end()){
        return stringToInt[str]; //返回编号
    }else{
        stringToInt[str] = numPerson;//str的编号对应为numperson
        intToString[numPerson] = str;
        return numPerson++;
    }
}
void DFS(int nowVisit,int& head,int& numMember,int& totalValue){
    numMember++;//成员人数+1;
    vis[nowVisit]=true;
    if(weight[nowVisit]>weight[head]) head = nowVisit;
    for(int i=0;i<numPerson;i++){
        if(G[nowVisit][i]>0){
            totalValue+=G[nowVisit][i];//连通块的总边权增加该边权
            G[nowVisit][i]=G[i][nowVisit]=0;//删除该条边，防止走回头路
            if(vis[i]==false) DFS(i,head,numMember,totalValue);
        }
    }
}

void DFSTravel(){
    for(int i=0;i<numPerson;i++){
        if(vis[i]==false){
            int head = i,numMember=0,totalValue=0;//头目，总成员，总边权
            DFS(i,head,numMember,totalValue);
            if(numMember>2&&totalValue>k)
                Gang[intToString[head]]=numMember;
        }
    }
}
int main(){
    int w;
    string str1,str2;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>str1>>str2>>w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1]+=w;
        weight[id2]+=w;
        G[id1][id2]+=w;
        G[id2][id1]+=w;
    }
    DFSTravel();
    cout<<Gang.size()<<endl;
    map<string,int>::iterator it;
    for(it=Gang.begin();it!=Gang.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}
