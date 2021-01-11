/*
1.������λ�洢������ĸ�λ�������ĵ�λ�洢������ĵ�λ��
2.�������ַ��������ʱ��ת��洢�������
*/
struct bign{
    int d[1010]��
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
        return 0;  //�������
    }
}

bign add(bign a,bign b){
    int carry = 0;
    bign c;
    for(int i=0;i<a.len||i<b.len;i++){
        c.d[c.len++] = (a.d[i] + b.d[i]+carry)%10;
        carry = (a.d[i] + b.d[i]+carry)/10;
    }
    if(carry!=0) c.d[c.len++] = carry; //���λ��Ϊ�㣬ֱ�Ӹ�����λ
    return c;
}
//�߾�����;������,����и��ţ��ȼ�¼���ٴ������ǵľ���ֵ��
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

//���������С�ڼ���������λ�������Ӹ���
bign sub(bign a,bign b){
    big c;
    for(int i=0;i<a.len||i<b.len;i++)
        if(a.d[i]<b.d[i]){   //�������������λ
            a.d[i+1]--;
            a.d[i]+=10;
        }
        c.[c.len++]=a.d[i] - b.d[i];
    }
    while(c.len>1&&c.d[c.len-1]==0) c.len--; //ȥ����λ�����㣬�����ٱ���һλ
    return c;
}

//�߾�����;��ȳ���
bign divide(bign a, int b,int &r){
    bign c;
    c.len = a.len; // �Ӹ�λ��ʼ���������������
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
