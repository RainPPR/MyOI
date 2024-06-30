#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

using ll = long long;

constexpr ll mod = 998244353;

#define add(x, t, p) x = (x + (t) % p + p) % p

ll solve(string s) {
    int n = int(s.size());
    vector<vector<ll>> f(n, vector<ll>(n));
    rep(i, n) f[i][i] = 1;
    for (int len = 2; len <= n; ++len)
    for (int l = 0; l + len - 1 < n; ++l) {
        int r = l + len - 1; f[l][r] = f[l + 1][r];
        if (s[l] == '(') for (int k = l + 1; k <= r; ++k) if (s[k] == ')')
        add(f[l][r], 1ll * f[k][r] * (k == l + 1 ? 1 : f[l + 1][k - 1]), mod);
    } return f[0][n - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; string s; cin >> T;
    while (T--) cout << solve((cin >> s, s)) << endl;
    return 0;
}
