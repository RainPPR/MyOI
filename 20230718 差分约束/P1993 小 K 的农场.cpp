#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr ll INF = 4e18;

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

int n, m;

struct graph {
    struct edge { int v, w; };
    vector<vector<edge>> e;
    graph() { e.clear(); }
    graph(int n) { e.resize(n + 1); }
    void add(int u, int v, int w) { e[u].push_back({v, w}); }
    void Add(int u, int v, int w) { add(u, v, w); add(v, u, w); }
} g;

bool check() {
    vector<ll> dis(n + 1, INF);
    vector<bool> vis(n + 1, 0);
    function<bool(int)> dfs = [&] (int u) -> bool {
        if (vis[u]) return true;
        vis[u] = true; for (auto i : g.e[u])
        if (dis[i.v] > dis[u] + i.w) {
            dis[i.v] = dis[u] + i.w;
            if (dfs(i.v)) return true;
        } return vis[u] = false;
    }; return (dis[0] = 0, !dfs(0));
}

signed main() {
    n = rr, m = rr, g = graph(n + 1);
    rep(i, n) g.add(0, i + 1, 0);
    rep(i, m) {
        int op = rr, a = rr, b = rr;
        if (op == 1) g.add(a, b, -rr);
        else if (op == 2) g.add(b, a, rr);
        else g.add(a, b, 0), g.add(b, a, 0);
    } printf(check() ? "Yes\n" : "No\n");
    return 0;
}
