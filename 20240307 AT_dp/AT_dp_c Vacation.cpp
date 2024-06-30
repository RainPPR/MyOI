#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

constexpr int N = 1e5 + 10;

int n, v[N][3], f[N][3];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n; rep(i, n) cin >> v[i][0] >> v[i][1] >> v[i][2];
	f[0][0] = v[0][0], f[0][1] = v[0][1], f[0][2] = v[0][2];
	for (int i = 1; i < n; ++i) {
		f[i][0] = max(f[i - 1][1], f[i - 1][2]) + v[i][0];
		f[i][1] = max(f[i - 1][0], f[i - 1][2]) + v[i][1];
		f[i][2] = max(f[i - 1][0], f[i - 1][1]) + v[i][2];
	} cout << *max_element(f[n - 1], f[n - 1] + 3) << endl;
	return 0;
}
