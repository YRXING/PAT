//栈
//STL中栈和队列没有实现清空
//while(!st.empty()){
//    st.pop();
//}

//读入一个只包含+-*/的非负整数计算表达式，计算表达式的值
/*
a.若为“(” 直接入栈
b.若为“)” 将符号栈中的元素依次出栈并输出, 直到 “(“, “(“只出栈, 不输出
c.若为其他符号, 将符号栈中的元素依次出栈并输出, 直到遇到比当前符号优先级更低的符号或者”(“。 将当前符号入栈。
扫描完后, 将栈中剩余符号依次输出

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



// 卡特兰数 1 1 2 5 14
/*
1. 合法的出栈序列
2. 有多少种括号匹配的括号序列
3. n + 1 个叶子节点能够构成多少种形状不同的（国际）满二叉树
（国际）满二叉树定义：如果一棵二叉树的结点要么是叶子结点，要么它有两个子结点，这样的树就是满二叉树。
4. 电影票一张 50 coin，且售票厅没有 coin。m 个人各自持有 50 coin，n 个人各自持有 100 coin。
 则有多少种排队方式，可以让每个人都买到电影票。

像这种一一匹配的问题（可以统一定义为+1和-1的匹配,且前缀和大于等于0的序列个数）就用卡特兰数
Catland = C(2n,n) - C(2n,n-1)
*/
