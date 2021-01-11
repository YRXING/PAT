#include<cstdio>
#include<map>
using namespace std;
map<int,int> mp;
int n,m,u,v,a[10010];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		mp[a[i]]=1;
	}
	for(int k=0;k<m;k++){
		scanf("%d%d",&u,&v);
		if(mp.find(u)==mp.end()&&mp.find(v)==mp.end())
			printf("ERROR: %d and %d are not found.\n",u,v);
		else if(mp.find(u)==mp.end())
			printf("ERROR: %d is not found.\n",u);
		else if(mp.find(v)==mp.end())
			printf("ERROR: %d is not found.\n",v);
		else{
			int LCA;
			for(int i=0;i<n;i++){
				if((a[i]>=u&&a[i]<=v)||(a[i]>=v&&a[i]<=u)){
					LCA=a[i];
                    break;
				}
			}
			if(LCA==u) printf("%d is an ancestor of %d.\n",u,v);
			else if(LCA==v) printf("%d is an ancestor of %d.\n",v,u);
			else printf("LCA of %d and %d is %d.\n",u,v,LCA);
		}
	}
	return 0;
}
