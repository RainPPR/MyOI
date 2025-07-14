#include <bits/stdc++.h>

using namespace std;

constexpr int N = 4210;

int n, p, ans, f[2][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, p; cin >> n >> p; f[0][2] = 1;
	for (int i = 3; i <= n; ++i) {
		for (int j = 2; j < i; ++j) f[i & 1][j] = (f[i & 1][j - 1] + f[(i - 1) & 1][i - j + 1]) % p;
		for (int j = i; j <= n; ++j) f[i & 1][j] = f[i & 1][j - 1];
	} for (int i = 1; i <= n; ++i) ans = (ans + f[n & 1][i]) % p;
	cout << ans * 2 % p << endl;
	return 0;
}
