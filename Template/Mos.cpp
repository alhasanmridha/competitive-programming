#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int BLOCK_SIZE = 316;
struct que{
	int l,r,i;
	bool operator <(que o){
		if(l/BLOCK_SIZE==o.l/BLOCK_SIZE) return r<o.r;
		return l/BLOCK_SIZE<o.l/BLOCK_SIZE;
	}
};

LL ans[100000];
int cnt[300010],lcomp[100001],ucomp[100001],cur[100001],st=1;
map<LL,int> mp;
LL ds;
int main(){
	int n,t;
	LL k;
	scanf("%d%lld",&n,&k);
	LL a[n];
	int typ[n];
	for(int i=0;i<n;i++) scanf("%d",typ+i);
	for(int i=0;i<n;i++){
		scanf("%lld",a+i);
		if(typ[i]==2) a[i]*=-1;
	}
	scanf("%d",&t);
	que q[t];
	for(int i=0;i<t;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].l--;
		q[i].r--;
		q[i].i=i;
	}
	sort(q,q+t);
	cnt[0]=1;
	mp[0]=0;
	cur[0]=0;
	if(mp.find(k)==mp.end()) mp[k]=st++;
	if(mp.find(-k)==mp.end()) mp[-k]=st++;
	lcomp[0]=mp[-k];
	ucomp[0]=mp[k];
	LL pref=0;
	for(int i=0;i<n;i++){
		pref+=a[i];
		if(mp.find(pref)==mp.end()) mp[pref]=st++;
		if(mp.find(pref+k)==mp.end()) mp[pref+k]=st++;
		if(mp.find(pref-k)==mp.end()) mp[pref-k]=st++;
		cur[i+1]=mp[pref];
		lcomp[i+1]=mp[pref-k];
		ucomp[i+1]=mp[pref+k];
	}
	int l=0,r=-1;
	for(int i=0;i<t;i++){
		que x=q[i];
		while(x.l<l){
			l--;
			ds+=cnt[ucomp[l]];
			cnt[cur[l]]++;
		}
		while(x.r>r){
			r++;
			ds+=cnt[lcomp[r+1]];
			cnt[cur[r+1]]++;
		}
		while(x.l>l){
			cnt[cur[l]]--;
			ds-=cnt[ucomp[l]];
			l++;
		}
		while(x.r<r){
			cnt[cur[r+1]]--;
			ds-=cnt[lcomp[r+1]];
			r--;
		}
		ans[x.i]=ds;
	}
	for(int i=0;i<t;i++) printf("%lld\n",ans[i]);
}
