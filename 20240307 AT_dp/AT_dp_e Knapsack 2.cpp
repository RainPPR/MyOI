#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

constexpr int N = 110;
constexpr int M = 1e5 + 10;

int n, s, W;
int w[N], v[N];

int f[N][M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> W; rep(i, n) cin >> w[i] >> v[i], s += v[i];
	fill(f[0] + 1, f[0] + s + 1, 0x3f3f3f3f), f[0][v[0]] = w[0];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < v[i]; ++j) f[i][j] = f[i - 1][j];
		for (int j = v[i]; j <= s; ++j) f[i][j] = min(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
	} for (int i = s; ~i; --i) if (f[n - 1][i] <= W) cout << i << endl, exit(0);
	return 0;
}
