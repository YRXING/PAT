/*
int         32λ         -2e-9~2e+9
long long   64λ         9e-18~9e+18  ��ֵ����2��31-1���ں����LL
float       32λ         3.4e-38~3.4e+38 ʵ�ʾ���6-7λ
double      64λ         1.7e-308~1.7e+308 ʵ�ʾ���15~16λ
*/



//#define pi 3.14 //���ų������궨��
//#define cal(x)  (((x*2)+1)) //������Ҫ�ú궨���������˶��峣��֮�������
//const double pi = acos(-1.0); //const����



/*
1.scanf %d ���Կհ׷�Ϊ�����жϱ�־
2.scanf %s ���Կո������Ϊ���������־
3.scanf %c ���Զ���հ׸�����
4.double �ͱ��� scanf %lf,printf %f
5.printf("%%") printf("\\")
6.%md %0md %.mf
7.gets ���Ի��з�\n��Ϊ���������puts�������һ������
8.sscanf(str,"%d",&n) sprintf(str,"%d",n)
9.PAT��������֧��gets������ʹ�ã����������
    cin.getline(s,len);  //�Ƽ�������
    fgets(s,len,stdin);
    string str;getline(cin,str);
10.scanf("%*c")��ʾ����Ҫ������
    printf("%*s",len,"****")//�����ռλ��,���㲹�ո�
    printf("%*.*s",a,b,"  ")//�ڶ��������������.
*/



//����math����
//floor(double x) //����ȡ��
//ceil(double x) //����ȡ��
//loga(b) = log(b)/log(a)
//(int)round(double x)//��������



//���� ����1e+6��Ҫ����������������
//int a[10] = {0};
//int a[10] = {};
//char str[100+1]; //�࿪һ��,���ʹ��getchar(),ĩβҪ�ֶ����\0�ַ�
//������Ϊ�������ں������޸ĵ�ͬ�ڶ�ԭ�����޸ġ�



//�������ıȽ�
//const double eps = 1e-8;
#define Equ(a,b) ((fabs((a)-(b)))<(eps))
#define More(a,b) (((a)-(b))>(eps))
#define Less(a,b)   (((a)-(b))<(-eps))
#define MoreEqu(a,b)    (((a)-(b))>(-eps))
#define LessEqu(a,b))   (((a)-(b))<(eps))



/*���Ӷ�����
1.һ��ojϵͳÿ����ܵ�����������Ϊ1e+7~1e+8,���o(n2)��n=1000�ǿ��Գ��ܵ�*/



/*������
1.while(scanf("%s",str)!=EOF){...}
  while(gets(str)!=NULL){...}
2.while...break
  while(scanf("%d%d",&a,&b),a||b)  �����ŵ�ѭ������
3.while(T--)
*/



/*ͼ�����
1.ͨ�����ɣ�ֱ�ӽ��������
2.����һ����ά�ַ����飬ͨ���������֮��Ȼ�����������ά���顣
3.��������2�������������������ͨ���ж����Ƿ���������������Ա��⸡�����Ľ��롣
*/

//strcmp��������ֵ�ɱ�������ͬ����һ����-1��1.
//��Ҫʹ��i<strlen(str)д������ʹ���Ӷ�������O(n2);
//������ int len=strlen(str);

//���������using namespace std;������䣬�Ͳ�ҪҪʹ��hash�������̵ı�������
//���ƵĻ���math.h��y1�����������ʹ��ȫ�ֱ���������������

/*malloc �� new
new ���ض������͵�ָ�룬malloc����void *
new ����ʧ��ʱ�׳�bad_alloc�쳣��malloc����NULL
����һ����int *a = new int()/new int,   (int *)malloc(sizeof(int))
ɾ��һ����delet a, free(a)
��������int *a = new int(n)/new int[n], (int *)malloc(n*sizeof(int))
ɾ�����: delete [] a, free(a)
*/

/*
tolower(char c)/toupper(char c)/ctype.h
strlwr(char *s)/strupr(char *s)/string.h
transform(str.begin(),str.end(),str.begin,::tolower/::toupper)/algorithm
*/
