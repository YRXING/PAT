//���䲻�ཻ���⣺
//����N��������(x,y)������ѡ�񾡿��ܶ�Ŀ����䣬ʹ����Щ����������û�н�����
//                           -----------
//                         ----------
//                       ---------
#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 110;
struct Interval{
    int x,y;//���������Ҷ˵�
}I[maxn];

bool cmp(Interval a,Interval b){
    if(a.x!=b.x) return a.x>b.x; //�Ȱ���˵�Ӵ�С����
    else return a.y<b.y //
}

int main(){
    int n;
    while(scanf("%d",&n)&&n!=0){
        for(int i=0;i<n;i++)
            scanf("%d%d",&I[i].x,&I[i].y);
        sort(I,I+n,cmp);
        //ans��¼���뽻���������lastX��¼��һ����ѡ�е�������Ҷ˵�
        int ans=1;lastX=I[0].x;
        for(int i=1;i<n;i++){
            if(I[i].y<=lastX){ //�����������Ҷ˵���lastX�����
                lastX=I[i].x;  //��I[i]��Ϊ��ѡ�е�����
                ans++;         //���ཻ���������1
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


//����ѡ������:
//����N�������䣬��������Ҫȷ�����ٸ��㣬����ʹÿ���������ж����ٴ���һ����
//ѡȡ��ͼ������˵ĵ�������������ܶ�ظ����������䡣
//�����������ֻ��Ҫ��I[i].y<=lastX.x��ΪI[i].y<lastX.x

