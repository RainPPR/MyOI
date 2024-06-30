#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll MOD = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s; cin >> s; int n = (int)s.size();
    vector<vector<int>> f(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) f[i][i] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
        }
    }

    for (int l = 0; l < n; ++l)
    for (int r = 0; r < n; ++r)
    printf("%d%c", f[l][r], " \n"[r == n - 1]);

    ll res = 0;
    for (int l = 0; l < n; ++l)
    for (int r = l; r < n; ++r)
    res = (res + ((l + 1) ^ (r + 1) ^ f[l][r])) % MOD;
    
    printf("%lld\n", res);
    return 0;
}
