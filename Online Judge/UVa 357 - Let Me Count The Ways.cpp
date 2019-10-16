#include <bits/stdc++.h>
using namespace std;
long long int dp[30001][5],a[5]={1,5,10,25,50};
int n;
long long int solve(int n, int i){
	if(n==0) return 1;
	if(i==5||n<0) return 0;
	if(dp[n][i]!=-1) return dp[n][i];
	return dp[n][i]=solve(n-a[i],i)+solve(n,i+1);
}
int main(){
	for(int i=0;i<30001;i++) for(int j=0;j<5;j++) dp[i][j]=-1;
	while(cin>>n){
		long long int ways=solve(n,0);
		if(ways==1)
			printf("There is only 1 way to produce %d cents change.\n",n);
		else
			printf("There are %lld ways to produce %d cents change.\n",ways,n);
	}
}
