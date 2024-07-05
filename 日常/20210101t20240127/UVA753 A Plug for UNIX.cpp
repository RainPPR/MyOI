#include <bits/stdc++.h>

using namespace std;

constexpr int N = 10010;
constexpr int M = 400010;

constexpr int INF = 1e9 + 10;

int n, m, k, s, t;
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

struct umap {
unordered_map<string, pair<int, int>> mp; int idx;
umap() { mp.clear(); idx = 0; }
int insert(string str) { if (!mp.count(str)) mp[str] = {++idx, 1}; else ++mp[str].second; return idx; }
int count(string str) { return mp.count(str) ? mp[str].second : 0; }
int id(string str) { return mp.count(str) ? mp[str].first : -1; }
int size() { return idx; }
};

int solev() {
    string id, fc; umap s1, s2; vector<pair<string, string>> app;
    cin >> n; for (int i = 1; i <= n; ++i) cin >> id, s1.insert(id);
    cin >> m; for (int i = 1; i <= m; ++i) cin >> fc >> id, s2.insert(id);
    umap s3 = s2;
    cin >> k; for (int i = 1; i <= k; ++i) cin >> id >> fc, app.push_back({id, fc}), s3.insert(id), s3.insert(fc);
    int ad = s3.size(); s = 0, t = n + ad + 1;
    memset(h, -1, sizeof h); idx = 0;
    for (auto i : s2.mp) Add(s, i.second.first, i.second.second);
    for (auto i : s1.mp) Add(i.second.first + ad, t, i.second.second);
    for (auto i : app) Add(s3.id(i.first), s3.id(i.second), INF);
    for (auto i : s1.mp) if (s3.count(i.first)) Add(s3.id(i.first), s1.id(i.first) + m, INF);
    return n - Dinic();
    // memset(h, -1, sizeof h); idx = 0;
    // umap mp;
    // s = 0, t = 53; string name; int cuse[300] = {0};
    // cin >> n; for (int i = 1; i <= n; ++i) cin >> c, ++cuse[c];
    // for (int i = 1; i <= 256; ++i) Add(i + 256, t, cuse[i]), cuse[i] = 0;
    // cin >> m; for (int i = 1; i <= m; ++i) cin >> name >> c, ++cuse[c];
    // for (int i = 1; i <= 256; ++i) Add(s, i, cuse[i]);
    // cin >> k; for (int i = 1; i <= k; ++i) cin >> u >> v, Add(u, v + 256, INF);
    // for (int i = 1; i <= 256; ++i) Add(i, i + 256, INF);
    // return n - Dinic();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--) cout << solev() << endl << endl;
    return 0;
}