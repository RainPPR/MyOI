#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

const int N = 410;
const int M = 2e5 + 10;

const int INF = 1e9;

int f, d, n, s, t;
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    memset(h, -1, sizeof h);
    cin >> n >> f >> d; s = 0, t = f + 2 * n + d + 1;
    for (int i = 1; i <= f; ++i) Add(s, i, 1);
    for (int i = 1; i <= n; ++i) Add(f + i, f + n + i, 1);
    for (int i = 1; i <= d; ++i) Add(f + 2 * n + i, t, 1);
    for (int i = 1; i <= n; ++i) {
        int c, w, q; cin >> c >> w;
        for (int j = 1; j <= c; ++j) cin >> q, Add(q, f + i, 1);
        for (int j = 1; j <= w; ++j) cin >> q, Add(f + n + i, f + 2 * n + q, 1);
    } cout << Dinic() << endl;
    return 0;
}