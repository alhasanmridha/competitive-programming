#include <iostream>
using namespace std;
int n,d,tot,ans,a[20];
void sol(int i,int amount,int mask){
	if(i>d||amount>n)
		return;
	if(amount>tot){
		tot=amount;
		ans=mask;
	}
	sol(i+1,amount,mask);
	sol(i+1,amount+a[i],mask|(1<<i));
}
int main(){
	while(scanf("%d%d",&n,&d)!=EOF){
		for(int i=0;i<d;i++){
			scanf("%d",a+i);
		}
		tot=0,ans=0;
		sol(0,0,0);
		for(int i=0;i<=d;i++)
			if((ans>>i)%2)
				cout<<a[i]<<" ";
		cout<<"sum:"<<tot<<"\n";
	}
}
