#include<bits/stdc++.h>
using namespace std;
#define sz 10001
typedef long long int LL;
int mob[sz], cntdiv[sz];
bool is_comp[sz];
vector < int > primes, a;
LL nc4(LL n) {
   LL ret = n * (n - 1) * (n - 2) * (n - 3);
   return ret / 24;
}
int main() {
   int t, n;
   mob[1] = 1;
   for (int i = 2; i < sz; i++) {
      if (!is_comp[i]) {
         primes.push_back(i);
         mob[i] = -1;
      }
      for (int j = 0; j < (int) primes.size() and i * primes[j] < sz; j++) {
         is_comp[primes[j] * i] = true;
         mob[primes[j] * i] = -1 * mob[i];
         if (i % primes[j] == 0) {
            mob[primes[j] * i] = 0;
            break;
         }
      }
   }
   cin >> t;
   for (int nt = 1; nt <= t; nt++) {
      cin >> n;
      a.clear();
      for (int i = 0; i < n; i++) {
         int num;
         scanf("%d", & num);
         a.push_back(num);
      }
      LL ans = 0;
      for (int i = 0; i < sz; i++) cntdiv[i] = 0;
      for (int n: a) {
         int i;
         for (i = 1; i * i < n; i++) {
            if (n % i == 0) {
               cntdiv[i]++;
               cntdiv[n / i]++;
            }
         }
         if (i * i == n) cntdiv[i]++;
      }
      for (int i = 1; i < sz; i++) {
         ans += mob[i] * nc4(cntdiv[i]);
      }
      cout << "Case " << nt << ": " << ans << "\n";
   }
}
