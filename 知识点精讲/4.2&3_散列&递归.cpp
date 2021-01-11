//-----------散列----------

/*将元素通过一个函数转化为一个整数，
使得该整数可以尽量唯一的代表这个元素。
这样便可使用数组下标来存放该元素，达到
空间换时间。*/

//1.一般可以使用STL的map来直接使用hash功能，
//  不需要自己实现解决冲突的办法。
//2.二维整点P映射为一个整数：Hash(P) = x*Rang+y;  0<=x,y<=Rang;
//3.字符串hash: 每个字母代表26进制的一个数，把26进制转化为10进制.
    int hashFunc(char S[],int len){
        int id=0;
        for(int i=0;i<len;i++)
            id = id*26+(S[i]-'A'); //和左移一位，加上填到空位的数。
        return id;
    }//len最大6位;
    //如果有小写，可转化为52进制
    //如果有数字，加上数字的值即可，或者增加进制.


//-----------递归-----------
//字典序全排列问题(八皇后问题)
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

