#include<bits/stdc++.h>
using namespace std;
#define M 1000005
vector<int> primes;
bool seive[M];
void precalc_primes(){
	for(int i=2;i<M;i++){
		if(!seive[i]) primes.push_back(i);
		for(int j=0;j<primes.size() and i*primes[j]<M;j++){
			seive[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
int main(){
	precalc_primes();
	for(int i=0;i<100;i++){
		cout<<primes[i]<<" ";
	}
	return 0;
}
