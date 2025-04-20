#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

constexpr int N = 2e5 + 10;

int n, Q, k;
int val[N];

vector<int> G[N];

ll pre[N];

int dep[N], fa[N][20];

void dfs(int u, int ff) {
    fa[u][0] = ff;
    dep[u] = dep[ff] + 1;
    pre[u] = pre[ff] + val[u];
    for (int k = 1; k < 20; ++k)
        fa[u][k] = fa[fa[u][k - 1]][k - 1];
    for (int v : G[u])
        if (v != ff)
            dfs(v, u);
}

int lca(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    for (int k = 19; k >= 0; --k)
        if (dep[fa[x][k]] >= dep[y])
            x = fa[x][k];
    if (x == y)
        return x;
    for (int k = 19; k >= 0; --k)
        if (fa[x][k] != fa[y][k])
            x = fa[x][k], y = fa[y][k];
    return fa[x][0];
}

ll solve_k0(int s, int t) {
    return pre[s] + pre[t] - pre[lca(s, t)] - pre[fa[lca(s, t)][0]];
}

ll solve_more(int s, int t) {
    return 1e18 + s + t;
}

void Main() {
    cin >> n >> Q >> k;
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    for (int i = 2; i <= n; ++i) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    dfs(1, 0);
    while (Q--) {
        int s, t;
        cin >> s >> t;
        ll ans = solve_k0(s, t);
        if (k != 0)
            ans = min(ans, solve_more(s, t));
        cout << ans << endl;
    }
    return;
}

signed main() {
    // freopen("transmit1.in", "r", stdin);
    // freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}