#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int mod = 998244353;

vector<int> multiply(vector<int> &f, vector<int> &g, int n) {
	vector<int> h(n + 3 << 2);
	for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= n; ++j)
	h[i + j] = (h[i + j] + 1ll * f[i] * g[j] % mod) % mod;
	return h;
}

int recur(vector<int> p, vector<int> q, int k, ll n) {
	vector<int> f, g, h(k + 1);
	for (; n; n >>= 1) {
		for (int i = 0; i <= k; ++i) h[i] = (i & 1) ? (mod - q[i]) : q[i];
		f = multiply(p, h, k), g = multiply(q, h, k);
		for (int i = 0; i <= k; ++i) q[i] = g[i << 1];
		for (int i = 0; i < k; ++i) p[i] = f[i << 1 | (n & 1)];
	} return p[0];
}

int solev(vector<int> &f, vector<int> &a, int k, ll n) {
	vector<int> q(k + 1); q[0] = 1;
	for (int i = 1; i <= k; ++i) q[i] = mod - f[i];
	a = multiply(a, q, k);
	a.resize(k + 1), a[k] = 0;
	return recur(a, q, k, n);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<int> f(k + 1), a(k + 1);
	for (int i = 1; i <= k; ++i) cin >> f[i];
	for (int i = 0; i < k; ++i) cin >> a[i];
	cout << solev(f, a, k, n) << endl;
    return 0;   
}
