#include<iostream>
#include<string>
using namespace std;
int kmp[1000000];
int main() {
    string s;
    cin >> s;
    int n = s.length(), j;
    for (int i = 1; i < n; i++) {
        j = kmp[i - 1];
        while (j > 0 and s[j] != s[i])
            j = kmp[j - 1];
        if (s[i] == s[j])
            j++;
        kmp[i] = j;
    }
    if (kmp[n - 1] > 0) {
        int period = n - kmp[n - 1];
        if (n % period == 0) {
            if (n / period > 2) {
                for (int i = 0; i < n - 2 * period; i++)
                    cout << s[i];
                return 0;
            }
        } else if (n - kmp[n - 1] < kmp[n - 1]) {
            for (int i = n - kmp[n - 1]; i < kmp[n - 1]; i++)
                cout << s[i];
            return 0;
        } else {
            for (int i = 0; i < n - 1; i++) {
                if (kmp[n - 1] <= kmp[i]) {
                    for (int k = 0; k < kmp[n - 1]; k++)
                        cout << s[k];
                    return 0;
                }
            }
            if (kmp[kmp[n - 1] - 1] > 0) {
                for (int i = 0; i < kmp[kmp[n - 1] - 1]; i++)
                    cout << s[i];
                return 0;
            }
        }
    }
    cout << "Just a legend\n";
}
