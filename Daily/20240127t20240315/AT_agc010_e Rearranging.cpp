#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2010;
#define gcd(a, b) __gcd(a, b)

int n, a[N], vis[N], perp[N][N];
vector<int> g[N];

void dfs(int k) {
    vis[k] = 1;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] || perp[i][k]) continue;
        g[k].push_back(i); dfs(i);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
    cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i]; sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) perp[i][j] = perp[j][i] = gcd(a[i], a[j]) == 1;
    priority_queue<int> q; for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i), q.push(i);
    while (q.size()) { int u = q.top(); q.pop(); cout << a[u] << " "; for (int v : g[u]) q.push(v); }
    return 0;
}
