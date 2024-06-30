#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100;
constexpr int M = 1e4 + 10;

constexpr int INF = 1e9 + 10;

int n, m, s, t;
int h[N], e[M], w[M], ne[M], idx;

void add(int u, int v, int x) { e[idx] = v, w[idx] = x, ne[idx] = h[u], h[u] = idx++; }
void Add(int u, int v, int x) { add(u, v, x), add(v, u, 0); }

int dep[N], cur[N];

bool bfs() {
	memset(dep, 0, sizeof dep);
	memcpy(cur, h, sizeof cur);
	queue<int> q; q.push(s);
	dep[s] = 1; while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i], x = w[i];
			if (x <= 0) continue;
			if (dep[v]) continue;
			dep[v] = dep[u] + 1;
			q.push(v);
		}
	} return dep[t];
}

int dfs(int u = s, int flow = INF) {
	if (u == t || !flow) return flow;
	int res = 0;
	for (int i = cur[u]; ~i; i = ne[i]) {
		cur[u] = i;
		int v = e[i], x = w[i];
		if (x <= 0) continue;
		if (dep[v] != dep[u] + 1) continue;
		int c = dfs(v, min(x, flow - res));
		w[i] -= c, w[i ^ 1] += c;
		res += c; if (res == flow) return res;
	} return res;
}

int Dinic() {
	int maxflow = 0;
	while (bfs()) maxflow += dfs();
	return maxflow;
}

void solev() {
	s = 1, t = 2; memset(h, -1, sizeof h);
    idx = 0; int u, v, x;
    for (int i = 1; i <= m; ++i) cin >> u >> v >> x, add(u, v, x), add(v, u, x);
    int c = Dinic();
    for (int i = 1; i <= n; ++i)
    for (int t = h[i]; ~t; t = ne[t])
    if (t & 1) w[t] = 0;
    else w[t] = bool(w[t]);
    c = Dinic();
    cout << c << endl;
    memset(dep, 0, sizeof dep);
	queue<int> q; q.push(s);
    set<pair<int, int>> ee;
	dep[s] = 1; while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i], x = w[i];
			if (x <= 0) {
                ee.emplace(minmax(u, v));
                continue;
            } if (dep[v]) continue;
			dep[v] = dep[u] + 1;
			q.push(v);
		}
	} for (auto t : ee)
        cout << t.first << " " << t.second << endl;
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> n >> m && n && m) solev();
	return 0;
}

