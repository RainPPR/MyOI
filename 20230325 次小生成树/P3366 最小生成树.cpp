#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr int INF = 1e9;
constexpr ll INF64 = 4e18;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

struct edge { int u, v, w; };
bool operator <(const edge &a, const edge &b) { return a.w < b.w; }

struct graph_vector {
    vector<edge> e;
    graph_vector() { e.clear(); }
    graph_vector(int m) { e.resize(m); }
};

struct graph_array {
    vector<vector<int>> e;
    graph_array() { e.clear(); }
    graph_array(int n) { e.resize(n + 1, vector<int>(n + 1, INF)); }
};

struct graph_list {
    vector<int> h, e, w, ne; int idx;
    graph_list() { idx = 0; }
    graph_list(int n, int m) { h.resize(n + 1), e.resize(m + 1), ne.resize(m + 1), w.resize(m + 1); idx = 0; }
    void add(int u, int v, int s) { ++idx; e[idx] = v; w[idx] = s; ne[idx] = h[u]; h[u] = idx; }
    void Add(int u, int v, int w) { add(u, v, w); add(v, u, w); }
};

struct dsu {
    vector<int> f;
    dsu(int n) { f.resize(n + 1); iota(f.begin(), f.end(), 0); }
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    bool merge(int a, int b) { a = find(a), b = find(b); return a == b ? 0 : (f[find(a)] = f[find(b)], 1); }
};

struct {
    int mst(int n, graph_vector &g) {
        sort(g.e.begin(), g.e.end());
        int res = 0, cnt = 0;
        dsu d(n); for (auto &i: g.e) {
            int u = i.u, v = i.v;
            if (!d.merge(u, v)) continue;
            res += i.w, ++cnt;
            if (cnt == n - 1) return res;
        } return -1;
    } int mst(int n, graph_array &g) {
        vector<int> dis(n + 1), vis(n + 1);
        fill(dis.begin(), dis.end(), INF);
        int res = 0; rep(i, n) {
            int t = -1; gor(j, 1, n + 1)
            if (!vis[j] && (t == -1 || dis[j] < dis[t])) t = j;
            if (i && dis[t] == INF) return -1;
            if (i) res += dis[t];
            gor(j, 1, n + 1) dis[j] = min(dis[j], g.e[t][j]);
            vis[t] = 1;
        } return res;
    } int mst(int n, graph_list &g) {
        vector<int> dis(n + 1), vis(n + 1);
        fill(dis.begin(), dis.end(), INF);
        priority_queue<pii, vector<pii>, greater<pii>> heap;
        heap.push({0, 1}); dis[1] = 0;
        int res = 0, cnt = 0; while (heap.size()) {
            int u = heap.top().second, d = heap.top().first;
            heap.pop(); if (vis[u]) continue;
            res += d; vis[u] = 1, ++cnt;
            for (int i = g.h[u]; i; i = g.ne[i]) {
                int v = g.e[i], w = g.w[i];
                if (w < dis[v]) dis[v] = w, heap.push({w, v});
            }
        } return cnt == n ? res : -1;
    }
} mst;

auto main() -> signed {
    int n = rr, m = rr; graph_list g(n, 2 * m);
    rep(i, m) {
        int u = rr, v = rr, w = rr;
        g.Add(u, v, w);
    } auto st = mst.mst(n, g);
    if (st == -1) printf("orz\n");
    else printf("%d\n", st);
    return 0;
}
