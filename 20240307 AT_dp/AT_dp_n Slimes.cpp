#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, l, r) for (decltype(r) i = l; i <= r; ++i)
#define per(i, r, l) for (decltype(l) i = r; i >= l; --i)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define chmax(a, h) a = max(a, h)
#define chmin(a, h) a = min(a, h)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n; vector<int> a(n + 1); vector<ll> s(n + 1);
	rep (i, 1, n) cin >> a[i], s[i] = s[i - 1] + a[i];
	vector<vector<ll>> f(n + 1, vector<ll> (n + 1, 0x3f3f3f3f3f3f3f3f));
	rep (i, 1, n) f[i][i] = 0;
	rep (l, 1, n) rep (i, 1, n - l + 1) rep (k, i + 1, i + l - 1)
	chmin(f[i][i + l - 1], f[i][k - 1] + f[k][i + l - 1] + s[i + l - 1] - s[i - 1]);
	cout << f[1][n] << endl;
	return 0;
}
