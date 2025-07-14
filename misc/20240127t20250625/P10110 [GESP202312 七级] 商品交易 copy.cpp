#include <bits/stdc++.h>

#define int ll
using ll = long long;

using namespace std;

constexpr int N = 1e5 + 10;
constexpr int M = 2e5 + 10;

int n, m, v[N];

vector<int> g[N];
#define add(u, v) g[u].push_back(v)

int vis[N], dep[N];
int bfs(int a, int b) {
    queue<int> q; q.push(a);
    dep[a] = 0; vis[a] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        if (u == b) return dep[u];
        for (int v : g[u]) if (!vis[v]) dep[v] = dep[u] + 1, vis[v] = 1, q.push(v);
    } return -1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    int a, b, x, y;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) cin >> x >> y, add(x, y);
    int q = bfs(a, b);
    cerr << a << " -> " << b << ": " << q << endl;
    if (q == -1) puts("No solution");
    else cout << v[b] - v[a] + q << endl;
    return 0;
}