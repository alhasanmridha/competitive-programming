#include<bits/stdc++.h>
using namespace std;
#define M 1000005
vector<int> prime;
bool seive[M];
int main(){
	for(int i=2;i<M;i++){
		if(!seive[i]) prime.push_back(i);
		for(int j=0;j<prime.size() and i*prime[j]<M;j++){
			seive[prime[j]*i]=true;
			if(i%prime[j]==0) break;
		}
	}
	for(int i=0;i<100;i++){
		cout<<prime[i]<<" ";
	}
	return 0;
}
