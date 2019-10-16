#include <bits/stdc++.h>
#define A(a,b) ((a>b)?a-b:b-a)
using namespace std;
int main(){
	int c,s,it=1;
	while(scanf("%d%d",&c,&s)==2){
		vector<int> con[5];
		vector<pair<int,int> >e;
		int t;
		double av=0;
		for(int i=0;i<s;i++){
			scanf("%d",&t);
			av+=(double)t;
			e.push_back({t,i});
		}
		av/=c;
		for(int i=s;i<2*c;i++){
			e.push_back({0,i});
		}
		sort(begin(e),end(e),greater<pair<int,int> >());
		vector<int> ans[2*c];
		for(int i=0;i<c;i++){
			vector<int>p;
			(e[i].second<e[2*c-i-1].second)?(p={e[i].first,e[2*c-i-1].first}):(p={e[2*c-i-1].first,e[i].first});
			ans[min(e[i].second,e[2*c-i-1].second)]=p;
		}
		cout<<"Set #"<<it++<<"\n";
		int cnt=0;
		double sum=0,tsum;
		for(int i=0;i<2*c;i++){
			if(ans[i].size()==0) continue;
			tsum=0;
			cout<<" "<<cnt++<<":";
			for(int j=0;j<ans[i].size();j++)
				if(ans[i][j]!=0){
					tsum+=(double)ans[i][j];
					cout<<" "<<ans[i][j];
				}
			cout<<"\n";
			sum+=A(tsum,av);
		}
		cout<<"IMBALANCE = "<<setprecision(5)<<fixed<<sum<<"\n\n";
	}	
}
