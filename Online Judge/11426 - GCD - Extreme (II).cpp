#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL phi[4000001],lpf[4000001],sphi[4000002];
vector<LL> primes;
LL get_phi(LL a){
	if(phi[a]!=0)
		return phi[a];
	LL p=lpf[a];
	LL pw=1;
	while(a%p==0){
		pw*=p;
		a/=p;
	}
	return phi[a*pw]=pw/p*(p-1)*get_phi(a);
}
int main(){
	LL n;
	phi[1]=1;
	for(LL i=2;i<4000001;i++){
		if(lpf[i]==0){
			primes.push_back(i);
			lpf[i]=i;
		}
		for(LL j=0;j<(LL)primes.size() and i*primes[j]<4000001 and primes[j]<=lpf[i];j++){
			lpf[primes[j]*i]=primes[j];
		}
	}
	for(int i=1;i<4000001;i++)
		sphi[i]=sphi[i-1]+get_phi(i);
	while(true){
		scanf("%lld",&n);
		if(n==0)
			return 0;
		LL ans=0;
		for(LL l=1;l*l<=n;l++){
			LL k=n/l;
			ans+=(k*(k-1)*get_phi(l))/2;
			if(k==l) break;
			ans+=(l*(l-1)*(sphi[n/l]-sphi[n/(l+1)]))/2;
		}
		printf("%lld\n",ans);
	}
}

