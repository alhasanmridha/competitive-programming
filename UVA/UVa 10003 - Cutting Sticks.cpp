#include <bits/stdc++.h>
using namespace std;
int a[52];
int dp[52][52];
int rec(int b,int e){
	if(b+1==e)
		return 0;
	if(dp[b][e]!=-1)
		return dp[b][e];
	int result=INT_MAX;
	for(int i=b+1;i<e;i++){
		result=min(result,rec(b,i)+rec(i,e));
	}
	return dp[b][e]=result+a[e]-a[b];
}
int main(){
	int l,n;
	a[0]=0;
	while(scanf("%d",&l),l){
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
		}
		a[n+1]=l;
		cout<<"The minimum cutting is "<<rec(0,n+1)<<".\n";
	}
	return 0;
}
