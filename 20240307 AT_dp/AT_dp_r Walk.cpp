#include <bits/stdc++.h>

using namespace std;

#define rep(i, l, r) for (decltype(r) i = (l); i <= (r); ++i)

using ll = long long;
constexpr int mod = 1e9 + 7;

struct emm {
	int n; vector<vector<int>> a;
	emm() = default;
	emm(int n): n(n) { a.resize(n + 1, vector<int>(n + 1)); }
	friend emm operator *(const emm &a, const emm &b) {
		int n = a.n; emm r(n);
		rep (i, 1, n) rep (k, 1, n) rep (j, 1, n)
		(r.a[i][j] += (1ll * a.a[i][k] * b.a[k][j] % mod)) %= mod;
		return r;
	}
};

emm qpow(emm a, ll k) {
	emm r = a; --k;
	while (k) {
		if (k & 1) r = r * a;
		a = a * a, k >>= 1;
	} return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; ll k; cin >> n >> k; emm a(n);
	rep (i, 1, n) rep (j, 1, n) cin >> a.a[i][j];
	emm q = qpow(a, k); int ans = 0;
	rep (i, 1, n) rep (j, 1, n) ans = (ans + q.a[i][j]) % mod;
	cout << ans << endl;
	return 0;
}
