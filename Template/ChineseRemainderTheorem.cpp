#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

LL GCD(LL a, LL b) { return (b == 0) ? a : GCD(b, a % b); }
LL LCM(LL a, LL b) { return a / GCD(a, b) * b; }
inline LL normalize(LL x, LL mod) { x %= mod; if (x < 0) x += mod; return x; }

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

pair<LL,LL> crt(vector< pair<LL,LL> > v){
	LL ans = v[0].first;
	LL lcm = v[0].second;
	for(int i = 1; i < v.size(); i++)
	{
		auto pom = ex_GCD(lcm, v[i].second);
		LL x1 = pom.x;
		LL d = pom.d;
		ans = normalize(ans + x1 * (v[i].first - ans) / d % (v[i].second / d) * lcm, lcm * v[i].second / d);
		lcm = LCM(lcm, v[i].second);
	}
	return {ans,lcm};
}

int main(){
	int t,tc=0,n;
	LL m,b;
	cin>>t;
	while(t--){
		vector< pair<LL, LL> > vll;
		cin>>n;
		while(n--){
			cin>>m>>b;
			vll.push_back({b,m});
		}
		pair<LL,LL> ans = crt(vll);
		cout<<"Case "<<++tc<<": "<<ans.first<<"\n";
	}
	return 0;
}
