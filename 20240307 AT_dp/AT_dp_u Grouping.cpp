#include <bits/stdc++.h>

using namespace std;

#define rep(i, l, r) for (decltype(r) i = l; i <= r; ++i)

using ll = long long;

constexpr int N = 20;

int n, a[N][N];
ll f[1 << N];

ll dfs(int s) {
	if (f[s] != -1) return f[s];
	ll res = 0;
	rep (i, 1, n) if ((s >> i - 1) & 1)
	rep (j, i + 1, n) if ((s >> j - 1) & 1) res += a[i][j];
	for (int i = (s - 1) & s; i; i = (i - 1) & s)
	res = max(res, dfs(i) + dfs(s ^ i));
	return f[s] = res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n; rep (i, 1, n) rep (j, 1, n) cin >> a[i][j];
	memset(f, -1, sizeof f); f[0] = 0;
	cout << dfs((1 << n) - 1) << endl;
	return 0;
}
