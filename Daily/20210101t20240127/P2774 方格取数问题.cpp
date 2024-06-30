#include <bits/stdc++.h>

#define int long long

using namespace std;

constexpr int N = 1e4 + 10;
constexpr int M = 1e5 + 10;

constexpr int INF = 1e9 + 10;
constexpr int dx[4] = {-1, 0, 0, 1};
constexpr int dy[4] = {0, -1, 1, 0};

int n, m, s, t;
int h[N], e[M], w[M], ne[M], idx;

inline int get(int x, int y) { return (x - 1) * m + y; }

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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m; s = 0, t = n * m + 1;
    int q, sum = 0; memset(h, -1, sizeof h);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        if ((i + j & 1) == 0) Add(get(i, j), t, (cin >> q, q));
        else {
            Add(s, get(i, j), (cin >> q, q));
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 1 || x > n || y < 1 || y > m) continue;
                Add(get(i, j), get(x, y), INF);
            }
        } sum += q;
    } cout << sum - Dinic() << endl;
    return 0;
}