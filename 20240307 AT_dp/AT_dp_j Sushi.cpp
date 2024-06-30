#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i <= n; ++i)

constexpr int N = 310;

int n, c[4];
double f[N][N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for (int i = 1, t; i <= n; ++i) cin >> t, ++c[t];
	rep(k, n) rep(j, n) rep(i, n) if (i | j | k) {
		double res = n;
		if (i) res += i * f[i - 1][j][k];
		if (j) res += j * f[i + 1][j - 1][k];
		if (k) res += k * f[i][j + 1][k - 1];
		f[i][j][k] = res / (1.0 * i + j + k);
	} printf("%.14lf\n", f[c[1]][c[2]][c[3]]);
	return 0;
}
