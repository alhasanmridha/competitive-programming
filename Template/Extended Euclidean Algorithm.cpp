#include<bits/stdc++.h>
using namespace std;
int ex_gcd(int a, int b, int &x, int &y){
	if(b==0){
	   x=1;
	   y=0;
	   return a;
	}
	int g=ex_gcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-(a/b)*y;
	return g;
}	
int main(){
	int a,b,x,y;
	cin>>a>>b;
	int g=ex_gcd(a,b,x,y);
	cout<<x<<" "<<y;
	return 0;
}
