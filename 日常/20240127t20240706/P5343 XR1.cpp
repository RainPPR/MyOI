#include <bits/stdc++.h>

using namespace std;

#define rep(i, l, r) for (decltype(r) i = l; i <= r; ++i)

#define endl '\n'

using ll = long long;

constexpr int mod = 1e9 + 7;

vector<int> multiply(vector<int> &f, vector<int> &g, int n) {
	vector<int> h(n + 3 << 2);
	for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= n; ++j)
	h[i + j] = (h[i + j] + 1ll * f[i] * g[j] % mod) % mod;
	return h;
}

int recur(vector<int> &a, vector<int> &f, int n, ll q) {
	a = multiply(a, f, n), a[n] = 0;
	vector<int> h(n + 1), at, ft;
	for (; q; q >>= 1) {
		rep (i, 0, n) h[i] = (i & 1) ? (mod - f[i]) : f[i];
		at = multiply(a, h, n), ft = multiply(f, h, n);
		rep (i, 0, n) f[i] = ft[i << 1], a[i] = at[i << 1 | (q & 1)];
	} return a[0];
}

int solev(vector<int> a, vector<int> f, int n, ll q) {
	a.resize(n + 1), f.resize(n + 1);
	f[0] = 1; rep (i, 1, n) f[i] = mod - f[i];
	return recur(a, f, n, q);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	ll n; cin >> n;
	int p, q, x; vector<int> aa(101), bb(101), f(101);
	cin >> p; for (int i = 0; i < p; ++i) cin >> x, aa[x] = 1;
	cin >> q; for (int i = 0; i < q; ++i) cin >> x, bb[x] = 1;
	for (int i = 1; i <= 100; ++i) f[i] = aa[i] && bb[i];
	vector<int> a(101); a[0] = 1;
	for (int i = 1; i < 100 && i <= n; ++i) for (int j = 1; j <= i; ++j) a[i] = (a[i] + 1ll * f[j] * a[i - j] % mod) % mod;
	if (n < 100) cout << a[n] << endl, exit(0);
	cout << solev(a, f, 100, n) << endl;
	return 0;
}