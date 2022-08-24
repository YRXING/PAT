//vector
vector<typename> name;
//如果typename是一个STL容器，定义时候加空格
vector<vector<int> >  //两个维度都是变长的
vector<int> vi[100] //vector数组,一维确定

//通过下标访问
name[index];
//通过迭代器
vector<typename>::iterator it=name.begin();//*(it+i)
//name[i]=====*(vi.begin()+i)

//注意！！！
//1.美国人习惯使用[begin,end)思想 name.end()指向rear下一个,不存任何元素
//2.只有vector和string才允许使用name.begin()+3这种迭代器加上整数的写法

//常用函数
push_back();
pop_back();
size();
clear();
insert(it,x);
erase(it)  erase(first,last) //[first,last)

//set,自动有序不重复
set<typename> name;
//只能通过迭代器访问
set<typename>::iterator it;//只能使用*(it++)
//常用函数
insert(x)
find(value) //返回迭代器
erase(it)  erase(value) erase(first,last)
size()
clear()

//string
string str="****",str("sfsdf");
//只能用cin,cout读入和输出,或者str.c_str()转为字符数组

//通过下标访问
str[i]
//通过迭代器
string::iterator it;// *(it+i)
str1+str2 //拼接
length()===size()
insert(pos,string)
insert(it,it2,it3)//it原字符串欲插入位置,it2 it3为待插入字符串的首位迭代器,左开右闭
erase(it) erase(first,last) erase(pos,length)
clear()
substr(pos,length)
string::npos //常数，值为-1，用作find()失败时的返回值
find(str2) //返回str2第一次出现的位置，失败返回string::npos
find(str2,pos)//从pos开始匹配
replace(pos,len,str2)//pos开始长度为len的替换为str2
replace(it1,it2,str2)
to_string()//基本类型转string
atoi(str.c_str())//<stdlib.h>，先把str转char数组在转基本类型
atof(str.c_str())


//map
//map可以将任何基本类型（包括STL容器）映射到任何基本类型，也就可以建立string到int的映射
map<typename1,typename2> mp;
map<string,int> mp;//只能用string不能用char数组
//map的键是唯一的
//通过下标访问
mp[key]
//通过迭代器
map<typename1,typename2>::iterator it;
it->first//访问键
it->second//访问值
//map 会以键从小到大自动排序
find(key)//返回迭代器,失败返回map.end()
erase(it) erase(key) erase(first,last)
size()
clear()


//queue
queue<typename> q;
q.front(),q.back()//只能通过这两种方式访问队首，队尾;使用前需要判断队列是否为空
push(x)
pop()
empty()
size()
//priority_queue
priority_queue<typename>  prio_q;
top()//只能通过它访问队首
push(x)
pop()
empty()
size()
//优先级的定义
//基本数据类型默认数字越大优先级越高
priority_queuw<Type,Container,Functional>; // Container可以是vector，dequeue
priority_queue<int,vector<int>,less<int> > q;//数字大优先级高
priority_queue<int,vector<int>,greater<int> >q;//数字小优先级高
/*
结构体优先级设置
*/
//1. 运算符重载
struct fruit{
    string name;
    int price;
    friend bool operator < (fruit f1,fruit f2){
        return f1.price<f2.price;
    }//无需重载> 和= ，会出错
};//队列内部以价格高的优先

// 2.重写仿函数
struct cmp{
    bool operator () (fruit f1,fruit f2){
        return f1.price>f2.price;
    }
};
priority_queue<fruit,vector<fruit>,cmp> q;
//如果结构体内的数据较为庞大，建议使用引用提高效率

//3. 传统比较器
bool cmp(fruit& a, fruit& b) {
    return a.price<b.price;
}

priority_queue<fruit,vector<fruit>,decltype(&cmp)> q(cmp);


//stack
stack<typename> s;
push(x)
top()
pop()
empty()
size()

//pair
//pair可以看做内部有两个元素的结构体，这两个元素的类型可以任意指定
#include<utility>//#include<map>
pair<typename1,typename2> p;
pair<string,int> p("haha",5)//可以进行初始化
pair<string,int>("haha",5),make_pair("hah",5) //临时构建一个pair
p=make_pair("xixi",5);p.first,p.second;//访问
//可以直接比大小，先比较first,在比较second
//用来代替二元结构体；作为map的键值对来进行插入
mp.insert(make_pair("heihei",5));

//algorithm常用函数
max(),min(),abs()//浮点型使用<cmath>里面的fabs()
swap(x,y)
reverse(it,it2)//将数组指针或迭代器在[it,it2)之间的元素反转
next_permutation()//给出序列在全排列中的下一个序列
//STL容器中只有vector,string,deque可以使用sort,其他已经有序
lower_bound(first,last,value)
upper_bound(first,last,value) //返回指针或者迭代器

max_element(first,last) //返回数组或容器中的最大值

/*erase问题
1.对于关联容器（如map，set，multimap，multiset），
删除当前的iterator，仅仅会使当前的iterator失效，只要在erase时，递增当前的iterator即可
set<int> valset = { 1,2,3,4,5,6 };
set<int>::iterator iter;
for (iter = valset.begin(); iter != valset.end(); )
{
     if (3 == *iter)
          valset.erase(iter++);
     else
          ++iter;
}
传给erase的是一个副本
2.对于序列式容器（如vector，deque，list等），
删除当前的iterator会使后面所有元素的iterator都失效。
这是因为vector，deque使用了连续分配的内存，
删除一个元素导致后面所有的元素会向前移动一个位置。
不过erase方法可以返回下一个有效的iterator。
vector<int> val = { 1,2,3,4,5,6 };
vector<int>::iterator iter;
for (iter = val.begin(); iter != val.end(); )
{
     if (3 == *iter)
          iter = val.erase(iter);     //返回下一个有效的迭代器，无需+1
     else
          ++iter;
}
*/

/*map是按照key从小到大来排序的,如果key是结构体,需要在结构体里面重载运算符
set也一样
struct node{
    ...
    bool operator<(const node& other) const{  //一定为const&

    }
};
