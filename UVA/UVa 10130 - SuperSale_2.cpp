#include <stdio.h>
int t,n,ans,p[1001],w[1001],g,mw,memo[1001][31];
int max(int a,int b){
	return a<b?b:a;
}
int dp(int i,int cw){
	return i==n?0:memo[i][cw]>-1?memo[i][cw]:memo[i][cw]=(cw-w[i]<0?dp(i+1,cw):max(p[i]+dp(i+1,cw-w[i]),dp(i+1,cw)));
}
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<=n;i++) for(int j=0;j<31;j++) memo[i][j]=-1;
		for(int i=0;i<n;i++) scanf("%d%d",p+i,w+i);
		scanf("%d",&g);
		for(int i=0;i<g;i++){
			scanf("%d",&mw);
			ans+=dp(0,mw);
		}
		printf("%d\n",ans);
	}
	return 0;
}
