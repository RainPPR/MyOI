#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, l, r) for (decltype(r) i = (l); i <= (r); ++i)
#define per(i, r, l) for (decltype(l) i = (r); i >= (l); --i)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define chmax(a, h) a = max(a, h)
#define chmin(a, h) a = min(a, h)

constexpr int mod = 1e9 + 7;

inline int lowbit(int x) {
	return x & -x;
}

int popc(int t) {
	int c = 0;
	while (t) t ^= lowbit(t), ++c;
	return c;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	vector<vector<int>> a(n + 1, vector<int> (n + 1));
	rep (i, 1, n) rep (j, 1, n) cin >> a[i][j];
	vector<int> f(1 << n); f[0] = 1;
	rep (S, 1, 1 << n) {
		int t = popc(S);
		rep (k, 1, n) if (((S >> k - 1) & 1) && a[t][k]) f[S] = (f[S] + f[S ^ (1 << k - 1)]) % mod;
	} cout << f[(1 << n) - 1] << endl;
	return 0;
}
