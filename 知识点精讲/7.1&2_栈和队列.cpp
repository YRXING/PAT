//ջ
//STL��ջ�Ͷ���û��ʵ�����
//while(!st.empty()){
//    st.pop();
//}

//����һ��ֻ����+-*/�ķǸ�����������ʽ��������ʽ��ֵ
/*
1.��map���������������ȼ���ӳ�䣬�˳�Ϊ1���Ӽ�Ϊ0.
2.�������ܵ��¸�����������������Ҫ��ɸ�����*/
#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

struct node{
    double num;//������
    char op;//������
    bool flag;//true��ʾ��������false��ʾ������
};//����������������ֿ������ǣ�������ÿһ�����붼Ҫ�жϣ�ջ�Ͷ���ҲҪ���ö��
string str;
stack<node> s;//������ջ
queue<node> q;//��׺���ʽ����
map<char,int> op;

void Change(){//��׺ת��׺
    double num;
    node temp;
    for(int i=0;i<str.length();){
        if(str[i]>='0'&&str[i]<='9'){//������
            temp.flag = true;
            temp.num = str[i++]-'0';
            while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
                temp.num = temp.num*10+(str[i]-'0');//����num
                i++;
            }
            q.push(temp);
        }else{//������
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
    while(!s.empty()) s.pop();//��ʼ��ջ
    Change();
    printf("%.2f\n",Cal());

    return 0;
}
