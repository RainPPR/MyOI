// Source: 洛谷
// Problem: P2634 [国家集训队] 聪聪可可
// Algorithm: 树形 DP
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Author: RainPPR
// Datetime: 2024-08-08 16:02

#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1

#define D(x) ({ void(0); })
#else
#define D(x) ({ auto t = (x); cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << t << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

// -----------------------------------------------------------------------------

using ll = long long;

constexpr int N = 2e4 + 10;

int n;

struct edge {
	int v, w;
	edge() = default;
	edge(int v, int w): v(v), w(w) {}
};

vector<edge> g[N];

int dp[N][3];

int fa[N];

bool vis[N];

vector<int> bfs() {
	vector<int> dfs;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 1;
		dfs.push_back(u);
		for (auto t : g[u]) {
			int v = t.v;
			if (vis[v])
				continue;
			fa[v] = u;
			q.push(v);
		}
	}
	return dfs;
}

void Main() {
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	vector<int> dfs = bfs();
	ll res = 0;
	for (auto it = dfs.rbegin(); it != dfs.rend(); ++it) {
		int u = *it;
		dp[u][0] = 1;
		dp[u][1] = dp[u][2] = 0;
		for (auto t : g[u]) {
			int v = t.v;
			if (v == fa[u])
				continue;
			int w = t.w;
			for (int i = 0; i < 3; ++i)
				res += 1ll * dp[u][i] * dp[v][(6 - i - w % 3) % 3];
			for (int i = 0; i < 3; ++i)
				dp[u][(i + w) % 3] += dp[v][i];
		}
	}
	ll a = res * 2 + n;
	ll b = 1ll * n * n;
	ll g = __gcd(a, b);
	cout << (a / g) << "/" << (b / g) << endl;
	return;
}

// -----------------------------------------------------------------------------

signed main() {
#ifdef FAST_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	Main();
	return 0;
}
