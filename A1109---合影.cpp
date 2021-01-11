#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
    string name;
    int height;
}node;

bool cmp(node a, node b){
    if(a.height == b.height){
        return a.name > b.name;
    }
    return a.height < b.height;
}

int main(){
    int n ,k;
    cin>>n>>k;
    vector<node> v;
    for(int i=0;i<n;i++){
        string n;
        int h;
        cin>>n>>h;
        node temp;
        temp.name = n;
        temp.height = h;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);

    int m = n / k; //每排几个人
    int y = n % k; //余数
    int count = n-1;
    int hang = 0;

    vector< vector<string> > ans(k+1);

    vector<string> temp(m+y);  //最后一排
    int p,q;
    temp[(m+y)/2] = v[count--].name;
    for(p = (m+y)/2-1, q = (m+y)/2+1; p>=0 && q<m+y; p--, q++){
        temp[p] = v[count--].name;
        temp[q] = v[count--].name;
    }
    if(p==0){
        temp[p] = v[count--].name;
    }
    for(int j=0;j<m+y;j++){
        ans[hang].push_back(temp[j]);
    }
    hang++;

    for(int i=0;i<k-1;i++){//前k-1排，没排m个人。
        vector<string> temp(m);
        int p,q;
        temp[(m)/2] = v[count--].name;
        for(p = (m)/2-1, q = (m)/2+1; p>=0 && q<m; p--, q++){
            temp[p] = v[count--].name;
            temp[q] = v[count--].name;
        }
        if(p==0){
            temp[p] = v[count--].name;
        }
        for(int j=0;j<m;j++){
            ans[hang].push_back(temp[j]);
        }
        hang++;
    }

    for(int i = 0; i < hang; i++){
        for(int j = 0; j<ans[i].size();j++){
            if(j!=0){
                cout<<" ";
            }
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}


//#include<stdio.h>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//const int N=10010;
//
//struct node{
//    char name[8];
//    int height;
//}total[N];
//
//vector<node> pailie;
//queue<node> ans;
//
//bool cmp(node a,node b){
//    if(a.height!=b.height) return a.height<b.height;
//    else return strcmp(a.name,b.name)>0;
//}
//
//int main(){
//    int n,k;
//    scanf("%d%d",&n,&k);
//    for(int i=1;i<=n;i++){
//        scanf("%s%d",total[i].name,&total[i].height);
//    }
//    sort(total+1,total+n+1,cmp);
//    int row=n/k;
//
//    for(int i=n;i>=row*k+1;i--) ans.push(total[i]);
//
//    for(int i=k;i>=1;i--){
//        for(int j=row*i;j>=row*(i-1)+1;j--){
//            ans.push(total[j]);
//        }
//        int num=ans.size();
//        int startPos=num/2+1;
//        int fu=1,zengliang=0;
//        pailie.clear();
//        pailie.resize(num+1);
//        while(!ans.empty()){
//            node top=ans.front();
//            ans.pop();
//            pailie[startPos]=top;
//            fu*=-1;
//            zengliang++;
//            startPos+=fu*zengliang;
//        }
//        for(int j=1;j<pailie.size();j++){
//            printf("%s",pailie[j].name);
//            if(j<pailie.size()-1) printf(" ");
//        }
//        printf("\n");
//    }
//    return 0;
//}
