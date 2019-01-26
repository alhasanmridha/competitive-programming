#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

struct GCD_type{
	LL x,y,d;
};

LL mod(LL a, LL M){
	return a%M;
}

GCD_type ex_GCD(LL a, LL b){
	if(b==0) return {1,0,a};
	GCD_type pom = ex_GCD(b,a%b);
	return {pom.y, pom.x - a/b * pom.y,pom.d};
}

int main(){

	LL n,m,a,b;
	cin>>a>>n>>b>>m;

	GCD_type pom = ex_GCD(n,m);

	if((a-b)%pom.d!=0){
		cout<<"no solution\n";
		continue;
	}

	LL lambda = pom.x*(b-a)/pom.d;
	LL lcm = (n*m)/pom.d;
	LL ans =(a + lambda%(m/pom.d)*n%lcm +lcm)%lcm;
	cout<<ans<<"  "<<lcm<<"\n";
	return 0;
}
