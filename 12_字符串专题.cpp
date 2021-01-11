//�ַ���hash����
H[i]=H[i-1]*26+index(str[i]);
//�ַ����ϳ�ʱ�������������ϴ�û�취��һ����������ͱ��棬��ʱֻ����ȥ��Ψһ�ԡ�
//�������Ľ��ȡģ
const int p=10000019;
const int mod=1000000007;
H[i]=(H[i-1]*p+index(str[i]))%mod;

/*����N��ֻ��Сд��ĸ���ַ����������в�ͬ���ַ����ĸ���
��N���ַ���hashת��ΪN������������ȥ�ء���ʹ��set��map����ֱ��һ��ʵ�֣������ٶ�����
*/
long long hashFuc(string str){
    long long H=0;
    for(int i=0;i<str.length();i++){
        H=(H*p+str[i]-'a')%mod;
    }
    return H;
}

//���Ӵ���hashֵ
H[i...j]=((H[j]-H[i-1]*p^j-i+1)%mod+mod)%mod;


//KMP
//next[i]��������ǰ��׺��ǰ׺���һλ���±�
/*
1.��ʼ��next����,��j=next[0]=-1;
2.��i��1-len-1�ķ�Χ����������ÿ��iִ��3.4
3.������j=next[j],ֱ��j����-1������s[i]=s[j+1];
4.���s[i]=s[j+1],��next[i]=j+1,����next[i]=j;
*/
void getNext(char s[],int len){
    int j=-1;
    next[0]=-1;
    for(int i=1;i<len;i++){
        while(j!=-1&&s[i]!=s[j+1])
            j=next[j];
        if(s[i]==s[j+1])
            j++;
        next[i]=j;
    }
}

/*KMP�㷨ʵ��
1.��ʼ��j=-1,��ʾpattern��ǰ�ѱ�ƥ������һλ
2.��i�����ı���text����ÿ��i��ִ��3.4����ͼƥ��text[i]��patter[j+1]
3.������j=next[j],ֱ��j����-1������text[i]==patter[j+1]
4.���text[i]=patter[j+1],����j++�����j�ﵽ��m-1��˵��pattern��text���Ӵ�
*/
bool KMP(char text[],char pattern[]){
    int n=strlen(text),m=strlen(pattern);
    getNext(pattern,m);//����pattern��next����
    int j=-1;
    for(int i=0;i<n;i++){
        while(j!=-1&&text[i]!=pattern[j+1])
            j=next[j];
        if(text[i]==pattern[j+1])
            j++;
        if(j==m-1)
            return true;
    }
    return false;
}

//text��pattern���ֵĴ���
int KMP(char text[],char pattern[]){
    int n=strlen(text),m=strlen(pattern);
    getNext(pattern,m);
    int ans=0,j=-1;
    for(int i=0;i<n;i++){
        while(j!=-1&&text[i]!=pattern[j+1])
            j=next[j];
        if(text[i]==pattern[j+1])
            j++;
        if(j=m-1;){
            ans++;
            j=next[j];
        }
    }
    return ans;
}
