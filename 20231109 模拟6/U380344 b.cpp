#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x" = " << " " << (x) << endl

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

constexpr int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #define add(x, t, p) x = (x + (t) % p + p) % p
    auto dp = [&] (string s, ll p) {
        int n = int(s.size()); vvi f(n, vi(n));
        rep(i, n) f[i][i] = 1;
        for (int len = 2; len <= n; ++len)
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1; f[l][r] = f[l + 1][r];
            if (s[l] == '(') for (int k = l + 1; k <= r; ++k)
            if (s[k] == ')') add(f[l][r], 1ll * f[k][r] * (k == l + 1 ? 1 : f[l + 1][k - 1]), p);
        } return f;
    }; string s; cin >> s; int n = int(s.size());
    auto f = dp(s, mod), g = dp(s, 1 << 9);
    ll ans = 0; rep(l, n) gor(r, l, n) {
        add(ans, f[l][r], mod);
        rep(k, 9) if (((l + 1) ^ (r + 1)) & (1 << k))
        add(ans, (1ll << k) * ((g[l][r] & (1 << k)) ? -1 : 1), mod);
    } printf("%lld\n", ans);
    return 0;
}
