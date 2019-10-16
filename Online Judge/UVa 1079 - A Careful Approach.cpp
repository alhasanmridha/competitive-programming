#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct limit{
	double st,en;
};
limit range[8];
int num,order[8];
int main(){
	int cnt=0,min,sec;
	while(cin>>num&&num!=0){
		for(int i=0;i<num;i++){
			cin>>range[i].st>>range[i].en;
			range[i].st*=60;
			range[i].en*=60;
			order[i]=i;
		}
		double pre,l,r,m,ans=-1.0;
		do{
			l=0,m,r=86400;
			while(r-l>.001){
				m=(r+l)/2;
				bool is_ok=true;
				pre=range[order[0]].st;
				for(int i=1;i<num;i++){
					if(pre+m>range[order[i]].en){
						is_ok=false;
						break;
					}
					pre=(pre+m>range[order[i]].st?pre+m:range[order[i]].st);
				}
				if(is_ok)
					l=m;
				else
					r=m;
			}
			ans=(ans<m?m:ans);
		}while(next_permutation(order,order+num));
		sec=round(ans);
		min=sec/60;
		sec-=min*60;
		cout<<"Case "<<++cnt<<": "<<min<<":"<<(sec<10?"0":"")<<sec<<"\n";
	}
}
