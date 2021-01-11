#include<cstdio>
#include<map>
#include<vector>
using namespace std;
const int maxn=10010;
bool notPrim[maxn]={0};//�Ƿ�������0�ǣ�1����
void Find_prime(){
    for(int i=2;i<maxn;i++){
        if(notPrim[i]==false)
        for(int j=i+i;j<maxn;j+=i) notPrim[j]=true;
    }
}

int Msize,n,m;

int main(){
    scanf("%d%d%d",&Msize,&n,&m);
    Find_prime();
    while(notPrim[Msize]) Msize++;
    int key;
    vector<int> Hash(Msize,0);
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        bool flag=false;
        for(int j=0;j<Msize&&!flag;j++){
            int index=(key+j*j)%Msize;
            if(Hash[index]==0) {Hash[index]=key;flag=true;}
        }
        if(!flag) printf("%d cannot be inserted.\n",key);
    }

    int total=0;
    for(int i=0;i<m;i++){
        scanf("%d",&key);
        for(int j=0;j<=Msize;j++){
                total++;
                int pos=(key+j*j)%Msize;//ƽ�����ҳ��ȵļ��㣡������
                if(Hash[pos]==key||Hash[pos]==0){
                    break;
                }
        }
    }
    printf("%.1f\n",(float)total/m);
    return 0;
}
