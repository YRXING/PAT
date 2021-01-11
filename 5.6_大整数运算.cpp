/*
1.整数高位存储在数组的高位，整数的低位存储在数组的低位；
2.整数按字符串读入的时候反转后存储在数组里；
*/
struct bign{
    int d[1010]；
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};

bign change(char str[]){
    bign a;
    a.len = strlen(str);
    for(i=0;i<a.len;i++){
        a.d[a.len-1-i]=str[i]-'0';
    }
    return a;
}


int compare(bign a,bign b){
    if(a.len>b.len) return 1;
    else if(a.len<b.len) return -1;
    else {
        for(int i=a.len-1;i>=0;i--){
            if(a.d[i]>b.d[i]) return 1;
            if(a.d[i]<b.d[i]) return -1;
        }
        return 0;  //两数相等
    }
}

bign add(bign a,bign b){
    int carry = 0;
    bign c;
    for(int i=0;i<a.len||i<b.len;i++){
        c.d[c.len++] = (a.d[i] + b.d[i]+carry)%10;
        carry = (a.d[i] + b.d[i]+carry)/10;
    }
    if(carry!=0) c.d[c.len++] = carry; //最后位不为零，直接赋给高位
    return c;
}
//高精度与低精度相乘,如果有负号，先记录，再代入他们的绝对值。
big multi(bign a,int b){
    int bign c;
    int carry = 0;
    for(int i=0;i<a.len;i++){
        c.d[c.len++] = (a.d[i] * b +carry)%10;
        carry = (a.d[i] * b+carry)/10;
    }
    while(carry!=0){
        c.d[c.len++] = carry%10;
        carry/=10;
    }
    return c;
}

//如果被减数小于减数，交换位置运算后加负号
bign sub(bign a,bign b){
    big c;
    for(int i=0;i<a.len||i<b.len;i++)
        if(a.d[i]<b.d[i]){   //如果不够减，借位
            a.d[i+1]--;
            a.d[i]+=10;
        }
        c.[c.len++]=a.d[i] - b.d[i];
    }
    while(c.len>1&&c.d[c.len-1]==0) c.len--; //去除高位多余零，且至少保留一位
    return c;
}

//高精度与低精度除法
bign divide(bign a, int b,int &r){
    bign c;
    c.len = a.len; // 从高位开始除，因此先令长度相等
    for(int i=c.len-1;i>=0;i--){
        r = r*10 +a[i];
        if(r<b) c.d[i] = 0;
        else{
            c.d[i] = r/b;
            r = r%b;
        }
    }
    while(c.len>1&&c.d[c.len-1]==0) c.len--;
    return c;
}
