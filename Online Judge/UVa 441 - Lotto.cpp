//Problem link:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=382
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int k;
	bool fst=true;
	while(cin>>k){
		if(k==0)
			return 0;
		cout<<(fst?"":"\n");
		fst=false;
		vector<int> v;
		int n;
		for(int i=0;i<k;i++){
			cin>>n;
			v.push_back(n);
		}
		vector<int>per_mut(k,1);
		for(int i=0;i<6;i++) per_mut[i]=0;
		do{
			int fnd=0;
			for(int i=0;i<k;i++){
				if(per_mut[i]==0){
					cout<<v[i]<<" ";
					fnd+=1;
				}
				if(fnd==5) break;
			}
			int last=k-1;
			while(per_mut[last]){
				last--;
			}
			cout<<v[last]<<"\n";
		}while(next_permutation(per_mut.begin(),per_mut.end()));
	}
}
