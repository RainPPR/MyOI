#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <queue>

#define for_in_mp(i, x) for (map<string, pair<int, int> >::iterator ____ = x.begin(); ____ != x.end(); ++____) { pair<string, pair<int, int> > i = *____;
#define for_in_vector(i, x) for (int ____ = 0; ____ < x.size(); ++____) { pair<string, string> i = x[____];

using namespace std;

const int N = 10010;
const int M = 400010;

const int INF = 1e9 + 10;

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
map<string, pair<int, int> > mp; int idx;
umap() { mp.clear(); idx = 0; }
int insert(string str) { if (!mp.count(str)) mp[str] = {++idx, 1}; else ++mp[str].second; return idx; }
int count(string str) { return mp.count(str) ? mp[str].second : 0; }
int id(string str) { return mp.count(str) ? mp[str].first : -1; }
int size() { return idx; }
};

int solev() {
    string id, fc; umap s1, s2; vector<pair<string, string> > app;
    int sum = 0;
    cin >> n; for (int i = 1; i <= n; ++i) cin >> id, s1.insert(id);
    cin >> m; for (int i = 1; i <= m; ++i) cin >> fc >> id, s2.insert(id);
    umap s3 = s2;
    cin >> k; for (int i = 1; i <= k; ++i) cin >> id >> fc, app.push_back({id, fc}), s3.insert(id), s3.insert(fc);
    int ad = s3.size(); s = 0, t = n + ad + 1;
    memset(h, -1, sizeof h); idx = 0;
    for_in_mp(i, s2.mp) Add(s, s3.id(i.first), i.second.second), sum += i.second.second/*, cerr << "INSERT S : " << i.first << "(" << s3.id(i.first) << ") " << i.second.second << endl*/; }
    for_in_mp(i, s1.mp) Add(s1.id(i.first) + ad, t, i.second.second)/* cerr << "INSERT T : " << i.first << "(" << s1.id(i.first) + ad << ") " << i.second.second << endl*/; }
    for_in_vector(i, app) Add(s3.id(i.first), s3.id(i.second), INF)/*, cerr << "INSERT CT : " << i.first << "(" << s3.id(i.first) << ") " << i.second << "(" << s3.id(i.second) << ")" << endl*/; }
    for_in_mp(i, s1.mp) if (s3.count(i.first)) Add(s3.id(i.first), s1.id(i.first) + ad, INF)/*, cerr << "INSERT SA : " << i.first << "(" << s3.id(i.first) << "," << s1.id(i.first) + ad << ")" << endl*/; }
    //cerr << s << " " << t << endl;
    return sum - Dinic();
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
    cin.tie(0), cout.tie(0);
    //int T; cin >> T;
    /*for (int i = 1; i <= T; ++i)*/ cout << solev()/* << (i == T ? "\n" : "\n\n")*/;
    return 0;
}