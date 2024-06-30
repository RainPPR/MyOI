#include <bits/stdc++.h>

#define int ll
using ll = long long;

using namespace std;

inline int judge(int yang, int you) {
    if (you == 1 && yang == 0) return 2;
    if (you == 2 && yang == 1) return 2;
    if (you == 0 && yang == 2) return 2;
    return yang == you;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];
    vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(n + 1, vector<int>(3, -1e9)));
    f[0][0][0] = f[0][0][1] = f[0][0][2] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < 3; ++k) {
                f[i][j][k] = f[i - 1][j][k] + judge(c[i], k) * a[i];
                if (j) for (int r = 0; r < 3; ++r)
                f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][r] - b[j] + judge(c[i], k) * a[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = max({ans, f[n][i][0], f[n][i][1], f[n][i][2]});
    cout << ans << endl;
    return 0;
}