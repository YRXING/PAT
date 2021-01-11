//栈
//STL中栈和队列没有实现清空
//while(!st.empty()){
//    st.pop();
//}

//读入一个只包含+-*/的非负整数计算表达式，计算表达式的值
/*
1.用map建立操作符和优先级的映射，乘除为1，加减为0.
2.除法可能导致浮点数，操作数类型要设成浮点数*/
#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

struct node{
    double num;//操作数
    char op;//操作符
    bool flag;//true表示操作数，false表示操作符
};//如果操作数操作符分开来考虑，则程序的每一步读入都要判断，栈和队列也要设置多个
string str;
stack<node> s;//操作符栈
queue<node> q;//后缀表达式序列
map<char,int> op;

void Change(){//中缀转后缀
    double num;
    node temp;
    for(int i=0;i<str.length();){
        if(str[i]>='0'&&str[i]<='9'){//操作数
            temp.flag = true;
            temp.num = str[i++]-'0';
            while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
                temp.num = temp.num*10+(str[i]-'0');//更新num
                i++;
            }
            q.push(temp);
        }else{//操作符
            temp.flag=false;
            while(!s.empty()&&op[str[i]]<=op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            temp.op=str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

double Cal(){
    double temp1,temp2;
    node cur,temp;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur.flag==true) s.push(cur);
        else{
            temp2=s.top().num;
            s.pop();
            temp1=s.top().num;
            s.pop();
            temp.flag=true;
            if(cur.op=='+') temp.num=temp1+temp2;
            else if(cur.op=='-') temp.num=temp1-temp2;
            else if(cur.op=='*') temp.num=temp1*temp2;
            else temp.num=temp1/temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}
int main(){
    op['+']=op['-']=1;
    op['*']=op['/']=2;
    getline(cin,str);
    for(string::iterator it = str.end();it!=str.begin();it--){
        if(*it==' ') str.erase(it);
    }
    while(!s.empty()) s.pop();//初始化栈
    Change();
    printf("%.2f\n",Cal());

    return 0;
}
