#include <bits/stdc++.h>

using namespace std;

constexpr int N = 510;
constexpr int M = 1e5 + 10;

constexpr int INF = 1e9;

int m, n, s, t, sum;
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

void print() {
    cout << 1 << endl;
    for (int i = 1; i <= m; ++i) {
        for (int j = h[i]; ~j; j = ne[j]) {
            if (w[j] == 1 || e[j] < m) continue;
            cout << e[j] - m << " ";
        } cout << endl;
    }
}

void solev() {
    int c = Dinic();
    if (c != sum) cout << 0 << endl;
    else print();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> m >> n; s = 0, t = n + m + 1;
    memset(h, -1, sizeof h); int tmp;
    for (int i = 1; i <= m; ++i) cin >> tmp, Add(s, i, tmp), sum += tmp;
    for (int i = 1; i <= n; ++i) cin >> tmp, Add(i + m, t, tmp);
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) Add(i, j + m, 1);
    solev(); return 0;
}