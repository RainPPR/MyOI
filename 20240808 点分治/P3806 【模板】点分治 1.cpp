#define M_DEBUG

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

constexpr int N = 3e4 + 10;
constexpr int M = 1e7 + 10;

int n, m;

vector<int> q;

struct edge {
	int v, w;
	edge() = default;
	edge(int v, int w): v(v), w(w) {}
};

vector<edge> g[N];

// -----------------------------------------------------------------------------

bool vis[N];

int tot, siz[N];

int root, max_son[N];

void dfs(int u, int fa) {
	siz[u] = 1;
	max_son[u] = -1;
	for (auto t : g[u]) {
		int v = t.v;
		if (v == fa)
			continue;
		if (vis[v])
			continue;
		dfs(v, u);
		max_son[u] = max(max_son[u], siz[v]);
		siz[u] += siz[v];
	}
	max_son[u] = max(max_son[u], tot - siz[u]);
	if (root == -1 || max_son[u] < max_son[root])
		root = u;
}

int get_root(int u) {
	tot = u == 1 ? n : siz[u];
	root = -1;
	dfs(u, -1);
	return root;
}

// -----------------------------------------------------------------------------

bool ans[N];

int dis[N], cnt;

void get_dis(int u, int fa, int val) {
	if (val > (int)1e7)
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

int mp[M];

void calc(int u) {
	mp[0] = 1;
	int mx = 0;
	for (auto t : g[u]) {
		int v = t.v;
		if (vis[v])
			continue;
		cnt = 0;
		get_dis(v, u, t.w);
		for (int i = 1; i <= cnt; ++i)
			for (int j = 0; j < m; ++j)
				if (q[j] >= dis[i])
					ans[j] |= mp[q[j] - dis[i]];
		for (int i = 1; i <= cnt; ++i)
			mp[dis[i]] = true, mx = max(mx, dis[i]);
	}
	memset(mp, 0, sizeof(int) * (mx + 1));
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

#define ANS(x) ((x) ? "Yes" : "No")

void Main() {
	cin >> n >> m;
	for (int i = 2; i <= n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	q.resize(m);
	copy_n(istream_iterator<int>(cin), m, q.begin());
	divide(get_root(1));
	for (int i = 0; i < m; ++i)
		puts(ANS(ans[i]));
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