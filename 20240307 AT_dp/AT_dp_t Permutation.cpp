#include <bits/stdc++.h>

using namespace std;

#define rep(i, l, r) for (decltype(r) i = l; i <= r; ++i)

constexpr int mod = 1e9 + 7;

using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, sum = 0; string s;
	cin >> n >> s; s = "#" + s;
	vector<int> f(n + 1), g(n + 1);
	f[1] = 1; rep (i, 2, n) {
		rep (j, 1, i - 1) g[j] = (g[j - 1] + f[j]) % mod;
		if (s[i - 1] == '<') rep (j, 1, i) f[j] = g[j - 1];
		else rep (j, 1, i) f[j] = (g[i - 1] - g[j - 1] + mod) % mod;
	} rep (i, 1, n) sum = (sum + f[i]) % mod;
	return cout << sum << endl, 0;
}
