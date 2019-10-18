#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define MOD 1000000007
#define S 100
LL fact[S];
LL fast(LL B, LL P) {
    if (P == 0) return 1;
    LL R;
    R = fast(B, P / 2) % MOD;
    R = R * R % MOD;
    if (P & 1) R = R * B % MOD;
    return R;
}
LL nck(LL n, LL r) {
    if (r > n) return 0;
    LL ans = 1;
    for (LL i = 0; i < r; i++) ans = ans * ((n - i) % MOD) % MOD;
    ans = (ans * fast(fact[r], MOD - 2)) % MOD;
    return ans;
}
int main() {
    fact[0] = 1;
    for (int i = 1; i < S; i++) fact[i] = i * fact[i - 1] % MOD;
    int k;
    LL n, a[50];
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    LL ans = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        LL tot = n, cnt = 0;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                tot -= a[i] + 1;
                cnt++;
            }
        }
        if (cnt & 1) ans -= nck(tot + k - 1, k - 1);
        else ans += nck(tot + k - 1, k - 1);
        if (ans < 0) ans += MOD;
        if (ans >= MOD) ans %= MOD;
    }
    cout << ans << "\n";
}
