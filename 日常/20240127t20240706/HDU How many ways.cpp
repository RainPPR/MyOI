#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1000;

struct matrix {
	int n, a[30][30];
	matrix() { n = 0; }
	void reset() { memset(a, 0, sizeof a); }
	matrix(int t) { n = t; reset(); }
	friend matrix operator *(const matrix &a, const matrix &b) {
		int n = a.n; matrix r(n);
		for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k)
		for (int j = 0; j < n; ++j)
		r.a[i][j] = (r.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod;
		return r;
	}
};

matrix qpow(matrix a, int k) {
	matrix r = a; --k;
	for (; k; k >>= 1) {
		if (k & 1) r = r * a;
		a = a * a;
	} return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, m;
	while (cin >> n >> m && n + m) {
		matrix a(n); int u, v;
		while (m--) cin >> u >> v, a.a[u][v] = 1;
		int t; cin >> t;
		while (t--) {
			int s, t, k; cin >> s >> t >> k;
			if (k == 0) {
				cout << (s == t) << endl;
				continue;
			}
			matrix q = qpow(a, k);
			cout << q.a[s][t] << endl;
		}
	}
	return 0;
}