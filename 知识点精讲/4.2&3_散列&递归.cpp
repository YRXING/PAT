//-----------ɢ��----------

/*��Ԫ��ͨ��һ������ת��Ϊһ��������
ʹ�ø��������Ծ���Ψһ�Ĵ������Ԫ�ء�
�������ʹ�������±�����Ÿ�Ԫ�أ��ﵽ
�ռ任ʱ�䡣*/

//1.һ�����ʹ��STL��map��ֱ��ʹ��hash���ܣ�
//  ����Ҫ�Լ�ʵ�ֽ����ͻ�İ취��
//2.��ά����Pӳ��Ϊһ��������Hash(P) = x*Rang+y;  0<=x,y<=Rang;
//3.�ַ���hash: ÿ����ĸ����26���Ƶ�һ��������26����ת��Ϊ10����.
    int hashFunc(char S[],int len){
        int id=0;
        for(int i=0;i<len;i++)
            id = id*26+(S[i]-'A'); //������һλ���������λ������
        return id;
    }//len���6λ;
    //�����Сд����ת��Ϊ52����
    //��������֣��������ֵ�ֵ���ɣ��������ӽ���.


//-----------�ݹ�-----------
//�ֵ���ȫ��������(�˻ʺ�����)
    void generateP(int index){
        if(index=n+1){
            for(int i=0;i<n;i++) printf("%d",P[i]);
            printf("\n");
            return;
        }

        for(int x=1;x<=n;x++){
            if(hashTable[x]==false){
                P[index] = x;
                hashTable[x]=true;
                generateP(index+1);
                hashTable[x]=false;
            }
        }
    }

