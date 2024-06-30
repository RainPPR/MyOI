#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3010;

int n; double p[N], f[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n; for (int i = 1; i <= n; ++i) cin >> p[i];
	f[0][0] = 1; for (int i = 1; i <= n; ++i) f[i][0] = f[i - 1][0] * (1 - p[i]);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) f[i][j] = f[i - 1][j] * (1 - p[i]) + f[i - 1][j - 1] * p[i];
	double ans = 0; for (int i = n + 1 >> 1; i <= n; ++i) ans += f[n][i];
	printf("%.10lf\n", ans);
	return 0;
}
