#include <bits/stdc++.h>
using namespace std;
#define max(X, Y)  ((X) > (Y) ? (X) : (Y))
int a[1000000],lis[1000000];
int main(){
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int cnt=1,i,j;
	while(scanf("%d",&a[0])&&a[0]!=-1){
		int it=0;
		while(scanf("%d",&a[++it])&& a[it]!=-1);
		for(i=0;i<it;i++)
			lis[i]=1;
		int best=1;
		for(i=1;i<it;i++){
			for(j=i-1;j>=0;j--){
				if(a[j]>=a[i]){
					lis[i]=max(lis[i],lis[j]+1);
				}
			}
			best=max(best,lis[i]);
		}
		if(cnt!=1){
			printf("\n");
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n", cnt++,best);
	}
}
