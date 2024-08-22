#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int N = 1e5 + 10;

ll dp[N];

#define max(a, b) ((a) > (b) ? (a) : (b))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, x; cin >> n;
    for (int i = 1; i <= n; i += 8) {
        dp[i] = -1e18;
        dp[i + 1] = -1e18;
        dp[i + 2] = -1e18;
        dp[i + 3] = -1e18;
        dp[i + 4] = -1e18;
        dp[i + 5] = -1e18;
        dp[i + 6] = -1e18;
        dp[i + 7] = -1e18;
    } for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = i; j; --j) dp[j] = max(dp[j], dp[j - 1] + 1ll * j * x);
    }
    ll mx = 0; for (int i = 1; i <= n; i += 8) {
        if (dp[i] > mx) mx = dp[i];
        if (dp[i + 1] > mx) mx = dp[i + 1];
        if (dp[i + 2] > mx) mx = dp[i + 2];
        if (dp[i + 3] > mx) mx = dp[i + 3];
        if (dp[i + 4] > mx) mx = dp[i + 4];
        if (dp[i + 5] > mx) mx = dp[i + 5];
        if (dp[i + 6] > mx) mx = dp[i + 6];
        if (dp[i + 7] > mx) mx = dp[i + 7];
    } cout << mx << endl;
	return 0;
}
