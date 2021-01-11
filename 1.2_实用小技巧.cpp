/*auto 关键字
auto可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型
类似于c#的var关键字
int a=10;
auto au_a=a;
auto自动类型推断发生在编译期，并不影响效率

auto关键字的正确用法：
1.用于代替冗长复杂，变量使用范围专一的变量声明
vector<int>::iterator it=ve.begin();
auto it = ve.begin();

2.定义模板函数时，用于声明以来模板参数的变量类型
template <typename _Tx,typename _Ty>
void Multiply(_Tx x, _Ty y)
{
    auto v = x*y;
    std::cout << v;
}

注意事项:
1.auto变量定义时候必须初始化，类似于const

在C语言中的全局变量和静态变量都是会自动初始化为0，
堆和栈中的局部变量不会初始化而拥有不可预测的值
*/

const int inf=(1<<30);

/*
#include<cctype>
isalpha 字母(包括大小写)
islower （小写字母）
isupper （大写字母）
isalnum（字母大写小写+数字）
isblank（space和\t）
isspace（space、\t、\r、\n）
char t=tolower（c）将字符转换为小写字符赋值给t
*/

//链表中有无效结点排序：在结构体中增加一个bool flag=false,将有效结点记为true
bool cmp(node a,node b){
    if(a.flag==false||b.flag==false) return a.flag>b.flag;
    else return a.value<b.value;
}

/*
散列表
常用方法：
1、除留余数法通常mod与表长取相同
2、平方探测法：正向：(H(key)+k²)%TSize   （考过2次）
          负向：((H(key)-k²)%TSize+TSize)%Tsize （未考）
*/

//递归解法
Node* getLCA(Node* root,int u,int v)
{
    if(root==nullptr) return nullptr;
    if(root->val > max(u,v)) return getLCA(root->lchild,u,v);
    else if(root->val < min(u,v)) return getLCA(root->rchild,u,v);
    else return root;
}

Node* getLCA(Node* root,int u,int v)
{
    if(root==nullptr || root->val==u || root->val==v) return root;
    Node* left=getLCA(root->lchild,u,v);
    Node* right=getLCA(root->rchild,u,v);
    if(left && right) return root;
    else return (left?left:right);
}




