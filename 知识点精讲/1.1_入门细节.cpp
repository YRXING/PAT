/*
int         32位         -2e-9~2e+9
long long   64位         9e-18~9e+18  赋值超过2’31-1需在后面加LL
float       32位         3.4e-38~3.4e+38 实际精度6-7位
double      64位         1.7e-308~1.7e+308 实际精度15~16位
*/



//#define pi 3.14 //符号常量、宏定义
//#define cal(x)  (((x*2)+1)) //尽量不要用宏定义来做除了定义常量之外的事情
//const double pi = acos(-1.0); //const常量



/*
1.scanf %d 是以空白符为结束判断标志
2.scanf %s 是以空格跟换行为读入结束标志
3.scanf %c 可以读入空白跟换行
4.double 型变量 scanf %lf,printf %f
5.printf("%%") printf("\\")
6.%md %0md %.mf
7.gets 是以换行符\n作为输入结束，puts输出紧跟一个换行
8.sscanf(str,"%d",&n) sprintf(str,"%d",n)
9.PAT编译器不支持gets函数的使用，解决方案：
    char* s;cin.getline(s,len);  //推荐！！！,参数为char* 类型，len代表读入字符的多少，一共可以读入len-1个，因为还有一个要给'\0'。
    fgets(s,len,stdin);
    string str;getline(cin,str);
    str.c_str()可以转为char*类型。
10.scanf("%*c")表示忽略要读的项
    printf("%*s",len,"****")//输出所占位宽,不足补空格
    printf("%*.*s",a,b,"  ")//第二个控制输出长度.
*/



//常用math函数
//floor(double x) //向下取整
//ceil(double x) //向上取整
//loga(b) = log(b)/log(a)
//(int)round(double x)//四舍五入



//数组 大于1e+6需要定义在主函数外面
//int a[10] = {0};
//int a[10] = {};
//char str[100+1]; //多开一个,如果使用getchar(),末尾要手动添加\0字符
//数组作为参数，在函数中修改等同于对原数组修改。



//浮点数的比较
//const double eps = 1e-8;
#define Equ(a,b) ((fabs((a)-(b)))<(eps))
#define More(a,b) (((a)-(b))>(eps))
#define Less(a,b)   (((a)-(b))<(-eps))
#define MoreEqu(a,b)    (((a)-(b))>(-eps))
#define LessEqu(a,b))   (((a)-(b))<(eps))



/*复杂度问题
1.一般oj系统每秒承受的运算次数大概为1e+7~1e+8,因此o(n2)在n=1000是可以承受的*/



/*多点测试
1.while(scanf("%s",str)!=EOF){...}
  while(gets(str)!=NULL){...}
2.while...break
  while(scanf("%d%d",&a,&b),a||b)  条件放到循环体中
3.while(T--)
*/



/*图形输出
1.通过规律，直接进行输出。
2.定义一个二维字符数组，通过规律填充之，然后输出整个二维数组。
3.整数除以2进行四舍五入操作可以通过判断它是否是奇数来解决，以避免浮点数的介入。
*/

//strcmp函数返回值由编译器不同而不一定是-1和1.
//不要使用i<strlen(str)写法，会使复杂度上升到O(n2);
//可以用 int len=strlen(str);

//如果引用了using namespace std;这条语句，就不要要使用hash这样变绿的变量名。
//类似的还有math.h的y1变量名，如果使用全局变量名，编译会出错

/*malloc 和 new
new 返回对象类型的指针，malloc返回void *
new 分配失败时抛出bad_alloc异常，malloc返回NULL
分配一个：int *a = new int()/new int,   (int *)malloc(sizeof(int))
删除一个：delet a, free(a)
分配多个：int *a = new int(n)/new int[n], (int *)malloc(n*sizeof(int))
删除多个: delete [] a, free(a)
*/

/*
tolower(char c)/toupper(char c)/ctype.h
strlwr(char *s)/strupr(char *s)/string.h
transform(str.begin(),str.end(),str.begin,::tolower/::toupper)/algorithm
reverse(begin,end)
*/
