#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main(){
	int t;
	LL n,ans;
	cin>>t;
	for(int nt=1;nt<=t;nt++){
		cin>>n;
		ans=0;
		LL i;
		for(i=2;i*i<=n;i++){
			ans+=i*(n/i-1);
			if(i==n/i) break;
			LL st=n/(i+1)+1;
			LL en=n/i;
			LL h=en-st+1;
			LL sum=(h*(2*st+h-1))/2;
			ans+=(i-1)*sum;
		}
		cout<<"Case "<<nt<<": "<<ans<<"\n";
	}
}
