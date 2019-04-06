#include<bits/stdc++.h>
using namespace std;
#define M 1000005
vector<int> primes;
bool seive[M];
int phi[M];
void precalc_primes(){
	phi[1]=1;
	for(int i=2;i<M;i++){
		if(!seive[i]){
			primes.push_back(i);
			phi[i]=i-1;
		}
		for(int j=0;j<primes.size() and i*primes[j]<M;j++){
			seive[primes[j]*i]=true;
			phi[primes[j]*i]=phi[i]*phi[primes[j]];
			if(i%primes[j]==0){
				phi[primes[j]*i]*=primes[j];
				phi[primes[j]*i]/=phi[primes[j]];
				break;
			}
		}
	}
}
int main(){
	precalc_primes();
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<phi[n]<<"\n";
	}
	return 0;
}
