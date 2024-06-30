#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

constexpr int N = 1e5 + 10;

int n, m, in[N];
vector<int> g[N];

int dep[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m; int u, v, ans = 0;
	rep(i, m) cin >> u >> v, g[u].push_back(v), ++in[v];
	queue<int> q; for (int i = 1; i <= n; ++i) if (!in[i]) q.push(i);
	while (q.size()) {
		u = q.front(), q.pop(), ans = max(ans, dep[u]);
		for (int v : g[u]) if (!--in[v]) dep[v] = dep[u] + 1, q.push(v);
	} cout << ans << endl;
	return 0;
}
