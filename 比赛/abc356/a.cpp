#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

constexpr int N = 1e6 + 10;

int n, cnt[N], sum[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n; for (int i = 0, x; i < n; ++i) cin >> x, ++cnt[x];
    for (int i = 1; i <= 1e6; ++i) sum[i + 1] = sum[i] + cnt[i];
    ll ans = 0;
    for (int a = 1; a <= 1e6; ++a) {
        ll c = cnt[a], res = 0;
        if (c == 0) continue;
        for (int l = a; l <= 1e6; l += a) {
            int r = min(l + a, (int)1e6 + 1);
            res += 1ll * (sum[r] - sum[l]) * (l / a);
        }
        ans += c * res - c * (c + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}