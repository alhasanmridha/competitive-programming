#include<bits/stdc++.h>
#define S 10000001
typedef long long int LL;
using namespace std;
vector < int > primes;
int lpf[S],/*lpf[i] is the lowest prime factor of i */ t, n;
int main() {
  for (int i = 2; i < S; i++) {
    if (!lpf[i]) {
      primes.push_back(i);
      lpf[i] = i;
    }
    for (int j = 0; j < (int) primes.size() and primes[j] <= lpf[i] and primes[j] * i < S; j++)
      lpf[i * primes[j]] = primes[j];
  }
  scanf("%d", & t);
  while (t--) {
    scanf("%d", & n);
    LL ans = 1;
    while (n > 1) {
      LL p = lpf[n];
      LL pw = 1;
      while (lpf[n] == p) {
        n /= p;
        pw *= p;
      }
      pw *= pw;
      pw -= (pw - 1) / (p + 1);
      ans *= pw;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
