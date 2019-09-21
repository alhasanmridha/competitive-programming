#include<bits/stdc++.h>
using namespace std;
#define S 1000001
typedef long long int LL;
LL c[S],mob[S];
int d[S];
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	bool is_prime[S];
	for(int i=0;i<S;i++){
		is_prime[i]=true;
		d[i]=0;
	}
	vector<int> primes;
	mob[1]=1;
	for(int i=2;i<S;i++){
		if(is_prime[i]){
			primes.push_back(i);
			mob[i]=-1;
		}
		for(int j=0;j<(int)primes.size() and primes[j]*i<S;j++){
			is_prime[primes[j]*i]=false;
			mob[primes[j]*i]=mob[primes[j]]*mob[i];
			if(i%primes[j]==0){
				mob[i*primes[j]]=0;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		int j;
		for(j=1;j*j<a[i];j++){
			if(a[i]%j==0){
				d[j]++;
				d[a[i]/j]++;
			}
		}
		if(j*j==a[i])
			d[j]++;
	}
	for(LL i=3;i<S;i++)
		c[i]=i*(i-1)*(i-2)/6;
	LL ans=0;
	for(int i=1;i<S;i++)
		ans+=mob[i]*c[d[i]];
	cout<<ans<<"\n";
	return 0;
}
