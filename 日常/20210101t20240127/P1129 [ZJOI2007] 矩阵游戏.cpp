#include <bits/stdc++.h>

using namespace std;

constexpr int N = 510;
constexpr int M = 1e5 + 10;

constexpr int INF = 1e9;

int n, s, t;
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
        res += c;
    } return res;
}

int Dinic() {
    int maxflow = 0;
    while (bfs()) maxflow += dfs();
    return maxflow;
}

bool solev() {
    int x; cin >> n; idx = 0;
    s = 0, t = 2 * n + 1;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; ++i) Add(s, i, 1);
    for (int j = 1; j <= n; ++j) Add(j + n, t, 1);
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    if ((cin >> x, x)) Add(i, j + n, 1);
    return Dinic() == n;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while (T--)
    cout << (solev() ? "Yes" : "No") << endl;;
    return 0;
}