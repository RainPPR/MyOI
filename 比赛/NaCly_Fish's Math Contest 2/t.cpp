#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> d, s;
vector<double> q;

vector<int> primes, isprime;
vector<int> phi;

void init() {
    d.resize(n + 1), s.resize(n + 1), q.resize(n + 1);
    for (int i = 1; i <= n; ++i) d[i] = d[i / 10] + 1, s[i] = s[i - 1] + d[i], q[i] = d[i] * log2(d[i]);
}

void euler() {
    primes.clear(), isprime.resize(n + 1, 1), phi.resize(n + 1);
    phi[1] = 1; for (int i = 2; i <= n; ++i) {
        if (isprime[i]) primes.push_back(i), phi[i] = i - 1;
        for (int j : primes) {
            if (j * i > n) break; isprime[j * i] = 0;
            if (i % j) phi[j * i] = phi[i] * (j - 1);
            else { phi[j * i] = phi[i] * j; break; }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n; init(); euler(); double res = 0;
    for (int a = 1; a <= n; ++a) res += phi[a] * (q[a] + s[int(n / a)]);
    printf("%.10lf", res); return 0;
}
