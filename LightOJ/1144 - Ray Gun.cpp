#include<bits/stdc++.h>
using namespace std;
#define S 1000001
typedef long long int LL;
LL mob[S];
LL solve(LL m, LL n){
    LL ans=m*n;
    for(LL i=2;i<=n;i++){
        ans+=mob[i]*(m/i)*(n/i);
    }
    ans+=m>0;
    ans+=n>0;
    return ans;
}
int main(){
    int m,n,t;
    cin>>t;
    for(int i=1;i<S;i++)
        mob[i]=2;
    for(int i=2;i<S;i++){
        if(mob[i]==2)
            mob[i]=-1;
        for(int j=2;j*i<S;j++){
            mob[j*i]=mob[i]*mob[j];
            if(i%j==0){
                mob[i*j]=0;
                break;
            }
        }
    }
 
    for(int nt=1;nt<=t;nt++){
        cin>>m>>n;
        cout<<"Case "<<nt<<": "<<solve(max(m,n),min(m,n))<<"\n";
    }
 
    return 0;
}
