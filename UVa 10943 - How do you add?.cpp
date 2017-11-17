#include<bits/stdc++.h>
using namespace std;
int c[200][100];
int main(){
	for(int i=0;i<200;i++){
		c[i][0]=1;
		for(int j=1;j<=min(99,i);j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%1000000;
		}
	}
	int n,k;
	while(scanf("%d%d",&n,&k)&&(n|k)){
		cout<<c[n+k-1][k-1]<<"\n";
	}
}
