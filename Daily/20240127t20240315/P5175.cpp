#include <bits/stdc++.h>

using ll = long long;
#define int ll

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
		r.a[i][j] = (r.a[i][j] + a.a[i][k] * b.a[k][j] % m) % m;
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

int solev() {
	int T, n, a1, a2, x, y; cin >> n >> a1 >> a2 >> x >> y;
	if (n == 1) return a1 * a1 % m;
	if (n == 2) return (a1 + a1 % m + a2 * a2 % m) % m;
	int a3 = (x * a2 % m + y * a1 % m) % m;
	int f3 = (a1 * a1 % m + a2 * a2 % m + a3 * a3 % m) % m;
	if (n == 3) return f3; emm a(4);
	a.a = { {1, x * x % m, (y * y % m + (2 * x * x % m) * y % m) % m, (2 * x * y % m) * y % m},
		    {0, x * x % m, (y * y % m + (2 * x * x % m) * y % m) % m, (2 * x * y % m) * y % m},
		    {0, 1, 0, 0}, {0, 0, x, y} };
	return a = qpow(a, n - 3), ((a.a[0][0] * f3 % m + (a.a[0][1] * a3 % m) * a3 % m) % m
							 + ((a.a[0][2] * a2 % m) * a2 % m
							 + (a.a[0][3] * a2 % m) * a1 % m) % m) % m;
}

signed main() {
	int T; cin >> T;
	while (T--) cout << solev() << endl;
	return 0;
}
