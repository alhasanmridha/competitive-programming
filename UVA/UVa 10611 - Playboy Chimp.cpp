#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q,h,inpt,a[50001];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&inpt);
		int low_in=(int)(lower_bound(a,a+n,inpt)-a);
		int up_in=(int)(upper_bound(a,a+n,inpt)-a);
		if(low_in>0) printf("%d ",a[low_in-1]);
		else printf("X ");
		if(up_in<n) printf("%d\n",a[up_in]);
		else printf("X\n");
	}
	return 0;
}
