#include <bits/stdc++.h>

using namespace std;

#define rep(i, l, r) for (decltype(r) i = (l); i <= (r); ++i)

constexpr int mod = 1e9 + 7;
constexpr int N = 1e5 + 10;

int n;

vector<int> g[N];
inline void add(int u, int v) { g[u].push_back(v); }
inline void Add(int u, int v) { add(u, v), add(v, u); }

int f[N][2];

int dfs(int u, int rt) {
	f[u][0] = f[u][1] = 1;
	for (int v : g[u]) if (v != rt) {
		f[u][0] = (1ll * f[u][0] * dfs(v, u)) % mod;
		f[u][1] = (1ll * f[u][1] * f[v][0]) % mod;
	} return (f[u][0] + f[u][1]) % mod;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n; int u, v;
	rep (i, 1, n - 1) cin >> u >> v, Add(u, v);
	cout << dfs(1, -1) % mod << endl;
	return 0;
}
