#include <bits/stdc++.h>

using namespace std;

constexpr int m = 1e9 + 7;

struct emm {
	int n;
	vector<vector<int>> a;
	emm() = default;
	emm(int n): n(n) { a.resize(n, vector<int>(n)); }
	friend emm operator *(const emm &a, const emm &b) {
		int n = a.n; emm r(n);
		for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k)
		for (int j = 0; j < n; ++j)
		r.a[i][j] = (r.a[i][j] + 1ll * a.a[i][k] * b.a[k][j] % m) % m;
		return r;
	}
};

emm qpow(emm a, int k) {
	emm r = a; --k;
	for (; k; k >>= 1) {
		if (k & 1) r = r * a;
		a = a * a;
	} return r;
}

int solve(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 0;
	emm a(5);
	a.a[0][0] = 1, a.a[0][1] = 1, a.a[0][2] = 2, a.a[0][3] = 0, a.a[0][4] = 1;
	a.a[1][0] = 1, a.a[1][1] = 0, a.a[1][2] = 0, a.a[1][3] = 0, a.a[1][4] = 0;
	a.a[2][0] = 0, a.a[2][1] = 0, a.a[2][2] = 1, a.a[2][3] = 1, a.a[2][4] = 0;
	a.a[3][0] = 0, a.a[3][1] = 0, a.a[3][2] = 1, a.a[3][3] = 0, a.a[3][4] = 0;
	a.a[4][0] = 0, a.a[4][1] = 0, a.a[4][2] = 0, a.a[4][3] = 0, a.a[4][4] = 1;
	a = qpow(a, n - 1);
	return ((a.a[0][2] + a.a[0][3]) % m - 2 * a.a[0][4] % m + m) % m;
}

signed main() {
	int t, n; cin >> t;
	while (t--) cout << solve((cin >> n, n)) << endl;
	return 0;
}
