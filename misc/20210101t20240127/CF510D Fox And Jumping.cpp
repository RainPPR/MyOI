// -> gcd(S) = 1, min price

#include <bits/stdc++.h>

using namespace std;

constexpr int N = 310;

#define gcd(a, b) __gcd(a, b)
#define Min(a, b) (a ? (a < b ? a : b) : b)
#define chmin(a, b) a = Min(a, b)

map<int, int> dp;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> l(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) cin >> l[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) {
        auto bak = dp;
        for (auto [v, s] : bak) {
            int g = gcd(v, l[i]);
            chmin(dp[g], s + c[i]);
        } chmin(dp[l[i]], c[i]);
    } if (!dp[1]) dp[1] = -1;
    cout << dp[1] << endl;
    return 0;
}
