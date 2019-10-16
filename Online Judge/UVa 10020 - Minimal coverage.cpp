#include <bits/stdc++.h>
using namespace std;
int main(){
	int C=1,m=100;
	cin>>C;
	while(C--){
		scanf("%d",&m);
		vector<pair<int,int> >v;//={{0,10},{0,15},{10,16},{90,100},{16,20},{20,50},{50,51},{51,99},{89,100},{91,95},{95,100}};
		vector<int> vin;
		int l,r;
		while(scanf("%d%d",&l,&r)){
			if(l==0&&r==0)
				break;
			v.push_back({l,r});
		}
		sort(begin(v),end(v),[](pair<int,int>a,pair<int,int>b){return ((a.first==b.first)?(a.second>b.second):(a.first<b.first));});
		int sz=v.size(),cnt=0,in;
		l=0,r=0;
		int lt,rt;
		bool found=true;
		for(int i=0;i<sz&&found;i++){
			if(r<v[i].first){
				found=false;
			}
			if(v[i].first<=l&&v[i].second>r){
				r=v[i].second;
				in=i;
			}
			if(r>=m){
				vin.push_back(in);
				//cout<<v[in].first<<" "<<v[in].second<<"\n";
				break;
			}
			if(v[i].first>l){
				vin.push_back(in);
				//cout<<v[in].first<<" "<<v[in].second<<"\n";
				l=v[in].second;
				i--;
			}
		}
		//cout<<lt<<" "<<rt<<"\n";
		if(!found){
			cout<<"0\n\n";
			continue;
		}
		else
			cout<<vin.size()<<"\n";
		for(int i=0;i<vin.size();i++){
			cout<<v[vin[i]].first<<" "<<v[vin[i]].second<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
