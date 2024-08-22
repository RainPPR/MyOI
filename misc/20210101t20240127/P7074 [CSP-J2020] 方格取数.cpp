#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

const int N = 1e3 + 10;

ll a[N][N], f[N][N];
ll dn[N][N], up[N][N];

signed main() {
    int n, m; scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) scanf("%lld", a[i] + j);
    f[0][0] = a[0][0];
    gor(i, 1, n) f[i][0] = f[i - 1][0] + a[i][0];
    gor(j, 1, m) {
        dn[0][j] = f[0][j - 1] + a[0][j], up[n - 1][j] = f[n - 1][j - 1] + a[n - 1][j];
        for (int i = 1; i < n; ++i) dn[i][j] = max(dn[i - 1][j], f[i][j - 1]) + a[i][j];
        for (int i = n - 2; ~i; --i) up[i][j] = max(up[i + 1][j], f[i][j - 1]) + a[i][j];
        for (int i = 0; i < n; ++i) f[i][j] = max(up[i][j], dn[i][j]);
    } printf("%lld\n", f[n - 1][m - 1]);
    return 0;
}
