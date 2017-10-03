#include <bits/stdc++.h>
using namespace std;
int dp[7501][5],a[5]={1,5,10,25,50},n;
int solve(int n, int i){
	if(n==0) return 1;
	if(i==5||n<0) return 0;
	if(dp[n][i]!=-1) return dp[n][i];
	return dp[n][i]=solve(n-a[i],i)+solve(n,i+1);
}
int main(){
	for(int i=0;i<7501;i++) for(int j=0;j<5;j++) dp[i][j]=-1;
	while(cin>>n) printf("%d\n",solve(n,0));
}
