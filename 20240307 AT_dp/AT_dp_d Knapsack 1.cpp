#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

constexpr int N = 110;
constexpr int M = 1e5 + 10;

int n, W;
int w[N], v[N];

ll f[N][M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> W; rep(i, n) cin >> w[i] >> v[i];
	for (int i = w[0]; i <= W; ++i) f[0][i] = v[0];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < w[i]; ++j) f[i][j] = f[i - 1][j];
		for (int j = w[i]; j <= W; ++j) f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
	} cout << *max_element(f[n - 1], f[n - 1] + W + 1) << endl;
	return 0;
}
