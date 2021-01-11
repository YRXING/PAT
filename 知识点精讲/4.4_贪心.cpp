//区间不相交问题：
//给出N个开区间(x,y)，从中选择尽可能多的开区间，使得这些开区间两两没有交集。
//                           -----------
//                         ----------
//                       ---------
#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 110;
struct Interval{
    int x,y;//开区间左右端点
}I[maxn];

bool cmp(Interval a,Interval b){
    if(a.x!=b.x) return a.x>b.x; //先按左端点从大到小排序
    else return a.y<b.y //
}

int main(){
    int n;
    while(scanf("%d",&n)&&n!=0){
        for(int i=0;i<n;i++)
            scanf("%d%d",&I[i].x,&I[i].y);
        sort(I,I+n,cmp);
        //ans记录不想交区间个数，lastX记录上一个被选中的区间的右端点
        int ans=1;lastX=I[0].x;
        for(int i=1;i<n;i++){
            if(I[i].y<=lastX){ //如果该区间的右端点在lastX的左边
                lastX=I[i].x;  //以I[i]作为新选中的区间
                ans++;         //不相交区间个数加1
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


//区间选点问题:
//给出N个闭区间，求最少需要确定多少个点，才能使每个闭区间中都至少存在一个点
//选取上图中最左端的点可以让它尽可能多地覆盖其他区间。
//因此上述代码只需要吧I[i].y<=lastX.x改为I[i].y<lastX.x

