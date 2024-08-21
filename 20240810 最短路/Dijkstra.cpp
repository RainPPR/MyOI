// Source: 洛谷
// Problem: P4779 【模板】单源最短路径（标准版）
// Algorithm: Dijkstra
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Author: RainPPR
// Datetime: 2024-08-10 16:25

#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1

#define D(x) ({ void(0); })
#else
#define D(x) ({ auto t = (x); cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << t << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

// -----------------------------------------------------------------------------

constexpr int N = 2e3 + 10;

int n, m;

struct edge {
	int v, w;
};

vector<edge> g[N];

int dis[N], vis[N];

bool dfs(int u) {
	if (vis[u])
		return true;
	vis[u] = 1;
	for (auto t : g[u]) {
		int v = t.v, w = t.w;
		if (dis[v] > dis[u] + w) {
			dis[v] = dis[u] + w;
			if (dfs(v))
				return true;
		}
	}
	vis[u] = 0;
	return false;
}

bool check(int s) {
	memset(vis, 0, sizeof(int) * (n + 1));
	memset(dis, 0x3f, sizeof(int) * (n + 1));
	dis[s] = 0;
	return dfs(s);
}

// -----------------------------------------------------------------------------

void Main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back(edge{v, w});
			if (w >= 0)
				g[v].push_back(edge{u, w});
		}
		puts(check(1) ? "YES" : "NO");
		for (int i = 1; i <= n; ++i)
			g[i].clear(), g[i].shrink_to_fit();
	}
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
