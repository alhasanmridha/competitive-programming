#include <bits/stdc++.h>
#define M 20000
using namespace std;
int main(){
	int n,m,k[M],d[M];
	while(scanf("%d%d",&n,&m)&&n&&m){
		for(int i=0;i<n;i++){
			scanf("%d",d+i);
		}
		for(int i=0;i<m;i++){
			scanf("%d",k+i);
		}
		sort(k,k+m);
		sort(d,d+n);
		int it=0,gold=0;
		for(int i=0;i<m&&it<n;i++){
			if(k[i]>=d[it]){
				it++;
				gold+=k[i];
			}
		}
		if(it==n){
			printf("%d\n",gold);
		}
		else{
			printf("Loowater is doomed!\n");
		}
	}
}
