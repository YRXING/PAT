#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100100;
int pos[maxn];

int main(){
    int n,ans=0;
    scanf("%d",&n);
    int left=n-1,num;//left��ų�0���ⲻ�ڱ�λ�����ĸ���
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        pos[num]=i;
        if(num==i&&num!=0) left--;
    }

    int k=1;//��ų�0���⵱ǰ���ڱ�λ�ϵ���С����
    while(left>0){
        if(pos[0]==0){
            while(k<n){
                if(pos[k]!=k){
                    swap(pos[0],pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while(pos[0]!=0){
            swap(pos[0],pos[pos[0]]);
            ans++;
            left--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
