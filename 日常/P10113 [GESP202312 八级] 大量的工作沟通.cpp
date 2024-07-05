#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;
constexpr int M = 2e5 + 10;

vector<int> g[N];

void add(int u, int v) { g[u].push_back(v); }
void Add(int u, int v) { add(u, v), add(v, u); }

int n, f[N];
int dep[N], mxj[N];
int lt[N][35];

void init(int u, int fa) {
    dep[u] = dep[fa] + 1, mxj[u] = max(u, mxj[fa]);
    for (int k = 0; k <= 30; ++k) lt[u][k + 1] = lt[lt[u][k]][k];
    for (int v : g[u]) if (v != fa) lt[v][0] = u, init(v, u);
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int k = 30; ~k; --k) if (dep[lt[x][k]] >= dep[y]) x = lt[x][k];
    if (x == y) return x;
    for (int k = 30; ~k; --k) if (lt[x][k] != lt[y][k]) x = lt[x][k], y = lt[y][k];
    return lt[x][0];
}

int solev() {
    int m, x, y; cin >> m >> x;
    for (int i = 1; i < m; ++i) cin >> y, x = lca(x, y);
    return mxj[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n; for (int i = 1; i < n; ++i) cin >> f[i], Add(i, f[i]);
    init(0, n); int q; cin >> q; while (q--) cout << solev() << endl;
    return 0;
}
