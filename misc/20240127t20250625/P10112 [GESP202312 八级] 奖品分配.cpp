#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1e9 + 7;

constexpr int N = 1010;

int s[N], sv[N];

int qpow(int a, int b) {
    int r = 1; while (b) {
        if (b & 1) r = 1ll * r * a % mod;
        a = 1ll * a * a % mod; b >>= 1;
    } return r;
}

void init(int n = N - 1) {
    s[0] = 1; for (int i = 1; i <= n; ++i) s[i] = 1ll * s[i - 1] * i % mod;
    sv[n] = qpow(s[n], mod - 2); for (int i = n; i; --i) sv[i - 1] = 1ll * sv[i] * i % mod;
}

int comb(int n, int m) {
    return (1ll * s[n] * sv[m] % mod) * sv[n - m] % mod;
}

int solev() {
    int n, m; cin >> n >> m;
    int sum = 0, ans = 1, t;
    for (int i = 1; i <= m; ++i)
    cin >> t, sum += t, ans = 1ll * ans * sv[t] % mod;
    return 1ll * s[sum] * ans % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; init();
    while (T--) cout << solev() << endl;
    return 0;
}
