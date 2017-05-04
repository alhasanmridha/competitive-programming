#include <iostream>
using namespace std;
#define inf (-1*1000000000);
int t,n,p[1001],w[1001],g,mw,memo[1001][31];
int dp(int i,int cw){
	if(cw<0) return inf;
	if(i==n) return 0;
	if(memo[i][cw]!=-1) return memo[i][cw];
	return memo[i][cw]=max(dp(i+1,cw),p[i]+dp(i+1,cw-w[i]));
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<=n;i++)
			for(int j=0;j<31;j++)
				memo[i][j]=-1;
		for(int i=0;i<n;i++){
			cin>>p[i]>>w[i];
		}
		cin>>g;
		int ans=0;
		for(int i=0;i<g;i++){
			cin>>mw;
			ans+=dp(0,mw);
		}
		cout<<ans<<"\n";
	}
}
