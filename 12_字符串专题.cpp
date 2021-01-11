//字符串hash进阶
H[i]=H[i-1]*26+index(str[i]);
//字符串较长时，产生的整数较大，没办法用一般的数据类型保存，此时只能舍去“唯一性”
//将产生的结果取模
const int p=10000019;
const int mod=1000000007;
H[i]=(H[i-1]*p+index(str[i]))%mod;

/*给出N个只有小写字母的字符串，求其中不同的字符串的个数
将N个字符串hash转换为N个整数，排序去重。（使用set或map可以直接一步实现，但是速度慢）
*/
long long hashFuc(string str){
    long long H=0;
    for(int i=0;i<str.length();i++){
        H=(H*p+str[i]-'a')%mod;
    }
    return H;
}

//求子串的hash值
H[i...j]=((H[j]-H[i-1]*p^j-i+1)%mod+mod)%mod;


//KMP
//next[i]就是最长相等前后缀中前缀最后一位的下标
/*
1.初始化next数组,令j=next[0]=-1;
2.让i在1-len-1的范围遍历，对于每个i执行3.4
3.不断令j=next[j],直到j回退-1，或是s[i]=s[j+1];
4.如果s[i]=s[j+1],则next[i]=j+1,否则next[i]=j;
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

/*KMP算法实现
1.初始化j=-1,表示pattern当前已被匹配的最后一位
2.让i遍历文本串text，对每个i，执行3.4来试图匹配text[i]和patter[j+1]
3.不断令j=next[j],直到j回退-1，或是text[i]==patter[j+1]
4.如果text[i]=patter[j+1],则令j++。如果j达到了m-1，说明pattern是text的子串
*/
bool KMP(char text[],char pattern[]){
    int n=strlen(text),m=strlen(pattern);
    getNext(pattern,m);//计算pattern的next数组
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

//text中pattern出现的次数
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
