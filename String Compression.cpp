#include<bits/stdc++.h>
using namespace std;
int pi[8000][8000],dp[8001],n;
string s;
int cnt_digit(int n){
	if(!n)
		return 0;
	return 1+cnt_digit(n/10);
}
int get_ans(int i, int j){
	if((j-i+1)%(j-i+1-pi[i][j])==0)
		return cnt_digit((j-i+1)/(j-i+1-pi[i][j]))+j-i+1-pi[i][j];
	return j-i+2;
}
int main(){
	cin>>s;
	n=s.length();
	for(int k=0;k<n;k++){
		dp[k]=k+1;
		for(int i=1+k;i<n;i++){
			int j=pi[k][i-1];
			while(j>0 and s[i]!=s[j+k])
				j=pi[k][j+k-1];
			if(s[i]==s[j+k])
				j++;
			pi[k][i]=j;
		}
	}
	dp[0]=0;
	dp[n]=n+1;
	for(int i=0;i<n;i++){
		for(int j=1;j+i<=n;j++){
			dp[i+j]=min(dp[i]+get_ans(i,i+j-1),dp[i+j]);
		}
	}
	cout<<dp[n];
	return 0;
}
