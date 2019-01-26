#include <iostream>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		int res=n;
		if(n%2==0){
			res-=res/2;
		}
		while(n%2==0) n/=2;
		for(int i=3;i*i<=n;i+=2){
			if(n%i==0){
				res-=res/i;
				while(n%i==0) n/=i;
			}
		}
		if(n>1){
			res-=res/n;
		}
		printf("%d\n",res);
	}
}
