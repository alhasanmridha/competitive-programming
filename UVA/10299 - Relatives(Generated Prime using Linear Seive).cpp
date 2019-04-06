#include<bits/stdc++.h>
using namespace std;
#define M 1000005
typedef long long int LL;
vector<LL> primes;
bool seive[M];
void precalc_primes(){
	for(LL i=2;i<M;i++){
		if(!seive[i]) primes.push_back(i);
		for(int j=0;j<primes.size() and i*primes[j]<M;j++){
			seive[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
LL get_totient(LL n){
	if(n==1) return 0;
	LL result=n;
	for(LL i=0;i*i<n;i++){
		if(n%primes[i]==0){
			while(n%primes[i]==0)
				n/=primes[i];
			result/=primes[i];
			result*=primes[i]-1;
		}
	}
	if(n!=1){
		result/=n;
		result*=n-1;
	}
	return result;
}
int main(){
	int n;
	precalc_primes();
	while(true){
		cin>>n;
		if(n==0) break;
		cout<<get_totient(n)<<"\n";
	}
	return 0;
}
