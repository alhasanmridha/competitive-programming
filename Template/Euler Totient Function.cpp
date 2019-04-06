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
int get_totient(int n){
    int result=n;
    precalc_primes();
    for(int i=0;i*i<n;i++){
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
    cin>>n;
    cout<<get_totient(n);
    return 0;
}
