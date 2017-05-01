#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int c,item[20],m,n,k,s_cost;
int cost[21][21];
int dp[21][201];
int solve(int in,int mleft){
	if(mleft<0)
		return -10000000;
	if(in==c) return m-mleft;
	if(dp[in][mleft]!=-1) return dp[in][mleft];
	int result=-1000;
	for(int i=0;i<item[in];i++){
		result=max(solve(in+1,mleft-cost[in][i]),result);
	}
	return dp[in][mleft]=result;
}
int main(){
	cin>>n;
	while(n--){
		memset(dp,-1,sizeof(dp));
		cin>>m>>c;
		int min_sum=0;
		vector<int>c_d;
		for(int i=0;i<c;i++){
			cin>>k;
			item[i]=k;
			int min=200000;
			for(int j=0;j<k;j++){
				cin>>s_cost;
				min=(s_cost<min?s_cost:min);
				cost[i][j]=s_cost;
			}
			min_sum+=min;
		}
		if(min_sum>m){
			cout<<"no solution\n";
			continue;
		}
		cout<<solve(0,m)<<"\n";
	}
	return 0;
}
