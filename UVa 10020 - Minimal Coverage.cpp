#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tc,m,l,r;
struct Seg{
	int l,r;
	bool operator<(const Seg& o){
		return l<o.l;
	}
};
int main(){
	bool fast=true;
	cin>>tc;
	while(tc--){
		vector<Seg>seg,final;
		cin>>m;
		Seg inp;
		while(cin>>l>>r){
			if(l==0&&r==0)
				break;
			inp.l=l;
			inp.r=r;
			seg.push_back(inp);
		}
		cout<<(fast?"":"\n");
		fast=false;
		sort(seg.begin(),seg.end());
		int left=0,right=0;
		bool flag=true;
		int i=0;
		while(i<seg.size()){
			if(seg[i].l>left){
				flag=false;
				break;
			}
			if(seg[i].r>left){
				right=seg[i].r;
				for(int j=i+1;seg[j].l<=left&&j<seg.size();j++){
					if(seg[j].r>right){
						right=seg[j].r;
						i=j;
					}
				}
				left=right;
				final.push_back(seg[i]);
				if(right>=m) break;
			}
			i+=1;
		}
		if(seg[seg.size()-1].r<m)
			flag=false;
		if(!flag){
			cout<<"0\n"; 
		}
		else{
			cout<<final.size()<<"\n";
			for(int i=0;i<final.size();i++){
				cout<<final[i].l<<" "<<final[i].r<<"\n";
			}
		}
	}
}
