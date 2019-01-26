#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[6];
	while(true){
		bool End=true;
		for(int i=0;i<6;i++){
			scanf("%d",a+i);
			if(a[i]!=0){
				End=false;
			}
		}
		if(End){
			break;
		}
		int cnt=a[5];
		cnt+=a[4];
		a[0]-=11*a[4];
		cnt+=a[3];
		int tsq=5*a[3];
		if(a[1]>tsq)
			a[1]-=tsq;
		else{
			tsq-=a[1];
			a[1]=0;
			a[0]-=2*tsq;
		}
		cnt+=(a[2]+3)/4;
		tsq=(4-a[2]%4)%4;
		if(tsq==1){
			if(a[1]>0){
				a[1]--;
				a[0]-=5;
			}
			else
				a[0]-=9;
		}
		else if(tsq==2){
			if(a[1]>2){
				a[1]-=3;
				a[0]-=6;
			}
			else{
				a[0]-=(18-a[1]*4);
				a[1]=0;
			}
		}
		else if(tsq==3){
			if(a[1]>4){
				a[1]-=5;
				a[0]-=7;
			}
			else{
				a[0]-=(27-a[1]*4);
				a[1]=0;
			}
		}
		if(a[1]>0){
			cnt+=(a[1]+8)/9;
			tsq=(9-a[1]%9)%9;
			a[0]-=4*tsq;
		}
		if(a[0]>0){
			cnt+=(a[0]+35)/36;
		}
		cout<<cnt<<"\n";
	}
}
