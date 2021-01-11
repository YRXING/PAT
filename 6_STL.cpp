//vector
vector<typename> name;
//���typename��һ��STL����������ʱ��ӿո�
vector<vector<int> >  //����ά�ȶ��Ǳ䳤��
vector<int> vi[100] //vector����,һάȷ��

//ͨ���±����
name[index];
//ͨ��������
vector<typename>::iterator it=name.begin();//*(it+i)
//name[i]=====*(vi.begin()+i)

//ע�⣡����
//1.������ϰ��ʹ��[begin,end)˼�� name.end()ָ��rear��һ��,�����κ�Ԫ��
//2.ֻ��vector��string������ʹ��name.begin()+3���ֵ���������������д��

//���ú���
push_back();
pop_back();
size();
clear();
insert(it,x);
erase(it)  erase(first,last) //[first,last)

//set,�Զ������ظ�
set<typename> name;
//ֻ��ͨ������������
set<typename>::iterator it;//ֻ��ʹ��*(it++)
//���ú���
insert(x)
find(value) //���ص�����
erase(it)  erase(value) erase(first,last)
size()
clear()

//string
string str="****",str("sfsdf");
//ֻ����cin,cout��������,����str.c_str()תΪ�ַ�����

//ͨ���±����
str[i]
//ͨ��������
string::iterator it;// *(it+i)
str1+str2 //ƴ��
length()===size()
insert(pos,string)
insert(it,it2,it3)//itԭ�ַ���������λ��,it2 it3Ϊ�������ַ�������λ������,���ұ�
erase(it) erase(first,last) erase(pos,length)
clear()
substr(pos,length)
string::npos //������ֵΪ-1������find()ʧ��ʱ�ķ���ֵ
find(str2) //����str2��һ�γ��ֵ�λ�ã�ʧ�ܷ���string::npos
find(str2,pos)//��pos��ʼƥ��
replace(pos,len,str2)//pos��ʼ����Ϊlen���滻Ϊstr2
replace(it1,it2,str2)
to_string()//��������תstring
atoi(str.c_str())//<stdlib.h>���Ȱ�strתchar������ת��������
atof(str.c_str())


//map
//map���Խ��κλ������ͣ�����STL������ӳ�䵽�κλ������ͣ�Ҳ�Ϳ��Խ���string��int��ӳ��
map<typename1,typename2> mp;
map<string,int> mp;//ֻ����string������char����
//map�ļ���Ψһ��
//ͨ���±����
mp[key]
//ͨ��������
map<typename1,typename2>::iterator it;
it->first//���ʼ�
it->second//����ֵ
//map ���Լ���С�����Զ�����
find(key)//���ص�����,ʧ�ܷ���map.end()
erase(it) erase(key) erase(first,last)
size()
clear()


//queue
queue<typename> q;
q.front(),q.back()//ֻ��ͨ�������ַ�ʽ���ʶ��ף���β;ʹ��ǰ��Ҫ�ж϶����Ƿ�Ϊ��
push(x)
pop()
empty()
size()
//priority_queue
priority_queue<typename>  prio_q;
top()//ֻ��ͨ�������ʶ���
push(x)
pop()
empty()
size()
//���ȼ��Ķ���
//������������Ĭ������Խ�����ȼ�Խ��
priority_queue<int,vector<int>,less<int> > q;//���ִ����ȼ���
priority_queue<int,vector<int>,greater<int> >q;//����С���ȼ���
//�ṹ�����ȼ�����
struct fruit{
    string name;
    int price;
    friend bool operator < (fruit f1,fruit f2){
        return f1.price<f2.price;
    }//��������> ��= �������
};//�����ڲ��Լ۸�ߵ�����

struct cmp{
    bool operator () (fruit f1,fruit f2){
        return f1.price>f2.price;
    }
};
priority_queue<fruit,vector<fruit>,cmp> q;
//����ṹ���ڵ����ݽ�Ϊ�Ӵ󣬽���ʹ���������Ч��


//stack
stack<typename> s;
push(x)
top()
pop()
empty()
size()

//pair
//pair���Կ����ڲ�������Ԫ�صĽṹ�壬������Ԫ�ص����Ϳ�������ָ��
#include<utility>//#include<map>
pair<typename1,typename2> p;
pair<string,int> p("haha",5)//���Խ��г�ʼ��
pair<string,int>("haha",5),make_pair("hah",5) //��ʱ����һ��pair
p=make_pair("xixi",5);p.first,p.second;//����
//����ֱ�ӱȴ�С���ȱȽ�first,�ڱȽ�second
//���������Ԫ�ṹ�壻��Ϊmap�ļ�ֵ�������в���
mp.insert(make_pair("heihei",5));

//algorithm���ú���
max(),min(),abs()//������ʹ��<cmath>�����fabs()
swap(x,y)
reverse(it,it2)//������ָ����������[it,it2)֮���Ԫ�ط�ת
next_permutation()//����������ȫ�����е���һ������
//STL������ֻ��vector,string,deque����ʹ��sort,�����Ѿ�����
lower_bound(first,last,value)
upper_bound(first,last,value) //����ָ����ߵ�����

/*erase����
1.���ڹ�����������map��set��multimap��multiset����
ɾ����ǰ��iterator��������ʹ��ǰ��iteratorʧЧ��ֻҪ��eraseʱ��������ǰ��iterator����
set<int> valset = { 1,2,3,4,5,6 };
set<int>::iterator iter;
for (iter = valset.begin(); iter != valset.end(); )
{
     if (3 == *iter)
          valset.erase(iter++);
     else
          ++iter;
}
����erase����һ������
2.��������ʽ��������vector��deque��list�ȣ���
ɾ����ǰ��iterator��ʹ��������Ԫ�ص�iterator��ʧЧ��
������Ϊvector��dequeʹ��������������ڴ棬
ɾ��һ��Ԫ�ص��º������е�Ԫ�ػ���ǰ�ƶ�һ��λ�á�
����erase�������Է�����һ����Ч��iterator��
vector<int> val = { 1,2,3,4,5,6 };
vector<int>::iterator iter;
for (iter = val.begin(); iter != val.end(); )
{
     if (3 == *iter)
          iter = val.erase(iter);     //������һ����Ч�ĵ�����������+1
     else
          ++iter;
}
*/

/*map�ǰ���key��С�����������,���key�ǽṹ��,��Ҫ�ڽṹ���������������
setҲһ��
struct node{
    ...
    bool operator<(const node& other) const{  //һ��Ϊconst&

    }
};
