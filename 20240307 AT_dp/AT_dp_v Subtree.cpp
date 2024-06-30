#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;

int n, m;
vector<int> e[N];

int f[N], g[N];
int pre[N], suf[N];

void init(vector<int> &son) {
    int p1 = 1, s1 = 1, q = son.size(), t;
    for (int i = 0; i < q; ++i) t = son[i], pre[t] = p1, p1 = 1ll * p1 * (f[t] + 1) % m;
    for (int i = q - 1; ~i; --i) t = son[i], suf[t] = s1, s1 = 1ll * s1 * (f[t] + 1) % m;
}

void dfs1(int u, int fa) {
    f[u] = 1; vector<int> son;
    for (int v : e[u]) if (v != fa) dfs1(v, u), f[u] = 1ll * f[u] * (f[v] + 1) % m, son.push_back(v);
    init(son);
}

void dfs2(int u, int fa) {
    if (fa == -1) g[u] = 1;
    else g[u] = ((1ll * g[fa] * pre[u] % m) * suf[u] % m + 1) % m;
    for (int v : e[u]) if (v != fa) dfs2(v, u);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    int u, v; cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
    dfs1(1, -1), dfs2(1, -1);
    for (int i = 1; i <= n; ++i) cout << 1ll * f[i] * g[i] % m << endl;
    return 0;
}
