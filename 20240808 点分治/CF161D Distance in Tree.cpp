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

using ll = long long;

// -----------------------------------------------------------------------------

constexpr int N = 5e4 + 10;

int n, k;

vector<int> g[N];

// -----------------------------------------------------------------------------

bool vis[N];

int root, tot;
int siz[N], son[N];

void dfs(int u, int fa) {
	siz[u] = 1;
	son[u] = -1;
	for (int v : g[u]) {
		if (v == fa)
			continue;
		if (vis[v])
			continue;
		dfs(v, u);
		son[u] = max(son[u], siz[v]);
		siz[u] += siz[v];
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

ll ans;

int dis[N], cnt;

void get_dis(int u, int fa, int dep) {
	if (dep > 500)
		return;
	dis[++cnt] = dep;
	for (int v : g[u]) {
		if (v == fa)
			continue;
		if (vis[v])
			continue;
		get_dis(v, u, dep + 1);
	}
}

int mp[1010];

void calc(int u) {
	mp[0] = 1;
	cnt = 0;
	for (int v : g[u]) {
		if (vis[v])
			continue;
		int st = cnt + 1;
		get_dis(v, u, 1);
		for (int i = st; i <= cnt; ++i)
			if (k >= dis[i])
				ans += mp[k - dis[i]];
		for (int i = st; i <= cnt; ++i)
			++mp[dis[i]];
	}
	for (int i = 1; i <= cnt; ++i)
		--mp[dis[i]];
}

void divide(int u) {
	vis[u] = true;
	calc(u);
	for (int v : g[u]) {
		if (vis[v])
			continue;
		divide(get_root(v));
	}
}

// -----------------------------------------------------------------------------

ll Main() {
	cin >> n >> k;
	for (int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	divide(get_root(1));
	return ans;
}

// -----------------------------------------------------------------------------

signed main() {
#ifdef FAST_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	cout << Main() << endl;
	return 0;
}