// Source: ¬Âπ»
// Problem: P4178 Tree
// Algorithm: µ„∑÷÷Œ
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// Author: RainPPR
// Datetime: 2024-08-08 14:53

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

constexpr int N = 1e4 + 10;
constexpr int V = 5e6 + 10;

int n, k;

struct edge {
	int v, w;
	edge() = default;
	edge(int v, int w): v(v), w(w) {}
};

vector<edge> g[N];

// -----------------------------------------------------------------------------

bool vis[N];

int root, tot;
int siz[N], son[N];

void dfs(int u, int fa) {
	siz[u] = 1;
	son[u] = -1;
	for (auto t : g[u]) {
		int v = t.v;
		if (v == fa)
			continue;
		if (vis[v])
			continue;
		dfs(v, u);
		siz[u] += siz[v];
		son[u] = max(son[u], siz[v]);
	}
	son[u] = max(son[u], tot - siz[u]);
	if (root == -1 || son[u] < son[root])
		root = u;
}

int get_root(int u) {
	tot = u == 1 ? n : siz[u];
	root = -1;
	dfs(u, -1);
	return root;
}

// -----------------------------------------------------------------------------

namespace ds {
	inline constexpr int hole(int k) {
		return k + (k >> 10);
	}

	ll s[hole(V)];
	uint64_t Tag, tag[hole(V)];

	void modify(int x, int v) {
		for (++x; x < V; x += x & -x) {
			if (tag[hole(x)] != Tag)
				s[hole(x)] = 0;
			s[hole(x)] += v;
			tag[hole(x)] = Tag;
		}
	}

	ll sum(int x) {
		ll r = 0;
		for (++x; x; x &= x - 1)
			if (tag[hole(x)] == Tag)
				r += s[hole(x)];
		return r;
	}

	void clear() {
		++Tag;
	}
}

ll ans;

int dis[N], cnt;

void get_dis(int u, int fa, int val) {
	if (val > k)
		return;
	dis[++cnt] = val;
	for (auto t : g[u]) {
		int v = t.v;
		if (v == fa)
			continue;
		if (vis[v])
			continue;
		get_dis(v, u, val + t.w);
	}
}

void calc(int u) {
	ds::modify(0, 1);
	cnt = 0;
	for (auto t : g[u]) {
		int v = t.v;
		if (vis[v])
			continue;
		int st = cnt + 1;
		get_dis(v, u, t.w);
		for (int i = st; i <= cnt; ++i)
			if (k >= dis[i])
				ans += ds::sum(k - dis[i]);
		for (int i = st; i <= cnt; ++i)
			ds::modify(dis[i], 1);
	}
	ds::clear();
}

void divide(int u) {
	vis[u] = true;
	calc(u);
	for (auto t : g[u]) {
		int v = t.v;
		if (vis[v])
			continue;
		divide(get_root(v));
	}
}

// -----------------------------------------------------------------------------

ll Main() {
	ans = 0;
	for (int i = 2; i <= n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		++u, ++v;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	divide(get_root(1));
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		g[i].shrink_to_fit();
		vis[i] = false;
	}
	return ans;
}

// -----------------------------------------------------------------------------

signed main() {
#ifdef FAST_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	while (cin >> n >> k && n && k)
		cout << Main() << endl;
	return 0;
}
