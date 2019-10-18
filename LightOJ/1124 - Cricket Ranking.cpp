#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define MOD 100000007
#define S 1000010
LL fact[S];
LL fast (LL B, LL P) {
    if(P==0) return 1;
    LL R;
    R=fast(B,P/2)%MOD;
    R=R*R%MOD;
    if(P&1) R=R*B%MOD;
    return R;
}
LL nck (int n, int r) {
    if(r > n) return 0LL;
    LL ans;
    ans = (fact[n] * fast(fact[r], MOD-2)) % MOD;
    ans = (ans * fast(fact[n-r], MOD-2)) % MOD;
    return ans;
}
int main(){
    fact[0]=1;
    for(int i=1;i<S;i++) fact[i]=i*fact[i-1]%MOD;
    int t;
    cin>>t;
    for(int nt=1;nt<=t;nt++){
        int k,n,l,a[50];
        cin>>k>>n;
        for(int i=0;i<k;i++){
            cin>>l>>a[i];
            n-=l;
            a[i]-=l;
        }
        LL ans=0;
        for(int mask=0;mask<(1<<k);mask++){
            int tot=n,cnt=0;
            for(int i=0;i<k;i++){
                if(mask & (1<<i)){
                    tot-=a[i]+1;
                    cnt++;
                }
            }
            if(cnt&1) ans-=nck(tot+k-1,k-1);
            else ans+=nck(tot+k-1,k-1);
            if(ans<0) ans+=MOD;
            if(ans>=MOD) ans%=MOD;
        }
        printf("Case %d: %lld\n",nt,ans);
    }
}
