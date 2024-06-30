#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1010;
constexpr int mod = 1e9 + 7;

int n, m, f[N][N];
string a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m; for (int i = 1; i <= n; ++i) cin >> a[i], a[i] = "#" + a[i];
	f[0][1] = 1; for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (a[i][j] != '#') f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
	cout << f[n][m] << endl;
	return 0;
}
