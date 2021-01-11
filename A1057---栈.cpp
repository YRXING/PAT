#include<stdio.h>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
stack<int> s;
int num=0,data,median;
int hashTable[N]={0};
int block[317]={0};

void operate(char str[]){
    if(strcmp(str,"Pop")==0) {
        if(s.empty()) printf("Invalid\n");
        else {
            int top = s.top();
            block[top/316]--;
            hashTable[top]--;
            s.pop();
            printf("%d\n",top);
            num--;
        }
    }
    else if(strcmp(str,"PeekMedian")==0){
            if(s.empty()) printf("Invalid\n");
            else {
                if(num%2==0) median=num/2;
                else median=(num+1)/2;
                int sum=0,k=0;
                while(sum+block[k]<median)
                    sum+=block[k++];
                int index = k*316;
                while(sum+hashTable[index]<median)
                    sum+=hashTable[index++];
                printf("%d\n",index);
            }
    }
    else {
        scanf("%d",&data);
        s.push(data);
        block[data/316]++;
        hashTable[data]++;
        num++;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char order[20];
    for(int i=0;i<n;i++){
        scanf("%s",order);
        operate(order);
    }
    return 0;
}
