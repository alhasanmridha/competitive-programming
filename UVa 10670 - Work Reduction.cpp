#include <bits/stdc++.h>
using namespace std;
struct cost_d
{
	char name[20];
	int cost=0;
	bool operator<(const cost_d& o){
		return (cost==o.cost?strcmp(name,o.name) < 0:cost<o.cost);
		
	}
};
int main(){
	int t,n,l,m,a,b;
	cin>>t;
	char ts[200];
	for(int i=1;i<=t;i++){
		cost_d c[100];
		cin>>n>>m>>l;
		for(int i=0;i<l;i++){
			scanf("%s",ts);
			int h;
			for(h=0;ts[h]!=':';h++){
				c[i].name[h]=ts[h];
			}
			c[i].name[h]='\0';
			sscanf(ts+h+1,"%d,%d",&a,&b);
			int tn=n;
			while(tn>m){
				if(tn/2>=m){
					c[i].cost+=min(b,(tn-tn/2)*a);
					tn/=2;
				}
				else{
					c[i].cost+=(tn-m)*a;
					tn=m;
				}
			}
		}
		sort(c,c+l);
		cout<<"Case "<<i<<"\n";
		for(int i=0;i<l;i++){
			printf("%s %d\n",c[i].name,c[i].cost );
		}
	}
	return 0;
}
