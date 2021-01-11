#include<cstdio>

const int up = 6;
const int down = 4;
int main(){
    int n;
    scanf("%d",&n);
    int a,ground=0,seconds=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        int diff=a-ground;
        seconds+=(diff>0)?diff*up:-diff*down;
        seconds+=5;
        ground = a;
    }
    printf("%d",seconds);
    return 0;
}
