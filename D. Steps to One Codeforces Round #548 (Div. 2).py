M=1000000007
m=int(input())
def get_prm_fctrs(n):
    p=2
    factors=[]
    while p*p<=n:
        if n%p==0:
            factors.append(p)
        while n%p==0:
            n//=p
        p+=1
    if n>1:
        factors.append(n)
    return factors
def get_n_coprimes(n,m):
    if n==1:
        return m
    l=len(prm_factors[n])
    ans=0
    for i in range(1,2**l):
        prod=1
        cnt=0
        for j in range(l):
            if ((1<<j) & i) > 0:
                prod*=prm_factors[n][j]
                cnt+=1
        if cnt&1==1:
            ans-=m//prod
        else:
            ans+=m//prod
    return m+ans
prm_factors=[[0],[0]]
for i in range(2,m+1):
    prm_factors.append(get_prm_fctrs(i))
dp=[m for i in range(m+1)]
for i in range(2,m+1):
    prod=2
    while prod*prod<i:
        if i%prod==0:
            dp[i]+=dp[prod]*get_n_coprimes(i//prod,m//prod)
            dp[i]+=dp[i//prod]*get_n_coprimes(prod,m//(i//prod))
        prod+=1
    if prod*prod==i:
        dp[i]+=dp[prod]*get_n_coprimes(i//prod,m//prod)
    dp[i]=(dp[i]*pow(m-m//i,M-2,M))%M
ans=0
for i in range(1,m+1):
    ans=(ans+dp[i])%M
print((ans*pow(m,M-2,M))%M)
