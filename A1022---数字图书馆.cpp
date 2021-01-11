#include<cstdio>
#include<map>
#include<string>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

map<string,set<int> > Library;

int main(){
    int n,id;
    scanf("%d",&n);
    string infor;
    for(int i=0;i<n;i++){
        scanf("%d",&id);
        getchar();
        for(int j=0;j<2;j++){
            getline(cin,infor);
            Library[infor].insert(id);
        }
        char c=' ';
        while(cin>>infor){
            Library[infor].insert(id);
            c=getchar();
            if(c=='\n') break;
        }
        getline(cin,infor);Library[infor].insert(id);
        getline(cin,infor);Library[infor].insert(id);
    }
    int time=0;
    string str;
    scanf("%d",&time);
    getchar();
    for(int i=0;i<time;i++){
        getline(cin,str);
        cout<<str<<endl;
        str = str.substr(3,str.length()-3);
        if(!Library[str].size()) printf("Not Found\n");
        else{
            set<int>::iterator it=Library[str].begin();
            for(it;it!=Library[str].end();it++){
                printf("%07d\n",*(it));
            }
        }
    }
    return 0;
}
/*
1.如果单独对查询提炼为一个函数，那么一定要对参数使用引用
2.在scanf或者cin输入书的编号id后，必须用getchar接收掉后面的空格，否则getline会将换行读入;
*/
