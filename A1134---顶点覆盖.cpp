#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    int n,m,k,nv,a,b,num;
    scanf("%d%d",&n,&m);
    vector<int> v[n];
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&nv);
        int flag=0;
        vector<int> Hash(m,0);//0--m-1�ű߶�û�д��ڹ�,��ʼ��Ϊ0;
        for(int j=0;j<nv;j++){
            scanf("%d",&num);
            for(int t=0;t<v[num].size();t++)
                Hash[v[num][t]]=1;
        }
        for(int j=0;j<m;j++){
            if(Hash[j]==0){
                printf("No\n");
                flag=1;
                break;
            }
        }
        if(flag==0)  printf("Yes\n");
    }
    return 0;
}

/*
��vector v[n]����ĳ������ڵ�ĳ���ߵı�ţ�����a b������㹹�ɵ������ߵı��Ϊ0��
��v[a].push_back(0)��v[b].push_back(0)������ʾa����0�űߣ�bҲ����0�űߡ�
����ÿһ���������жϣ����������е�ÿһ��Ԫ�أ�
����ǰԪ���ܹ����ڵıߵı��i��Ӧ��hash[i]���Ϊ1��
��ʾ��������������һ�������Լ���S�еġ�
����ж�hash�����е�ÿһ��ֵ�Ƿ���1������в���1�ģ�
˵�������ߵ����˽��û��һ�����Լ���S�У������No���������Yes��
*/

