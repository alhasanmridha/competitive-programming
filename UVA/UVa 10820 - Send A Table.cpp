#include <iostream>
using namespace std;
int main(){
	int N;
	while(scanf("%d",&N)&&N){
		int ans=0;
		for(int i=2;i<=N;i++){
			int n=i;
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
			ans+=res;
		}
		printf("%d\n",ans*2+1);
	}
}
