#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

constexpr int N = 2510;

int n, m, k;

vector<int> G[N];

vector<int> reach[N];
bool is[N][N];

void init_dis(int s) {
    static bool vis[N];
    memset(vis, 0, sizeof(bool) * (n + 1));

    queue<pair<int, int>> q;
    q.emplace(s, 0);

    while (!q.empty()) {
        int u = q.front().first;
        int w = q.front().second;
        q.pop();

        if (vis[u])
            continue;
        vis[u] = true;

        if (u != s)
            reach[s].push_back(u);
        is[s][u] = 1;

        if (w > k)
            continue;
        for (int v : G[u]) {
            if (vis[v])
                continue;
            q.emplace(v, w + 1);
        }
    }
}

ll val[N];

void Main() {
    cin >> n >> m >> k;
    for (int i = 2; i <= n; ++i)
        cin >> val[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        init_dis(i);
    ll ans = -1e9;
    for (int a : reach[1])
        for (int b : reach[a])
            if (b != 1)
                for (int c : reach[b])
                    if (c != a && c != 1)
                        for (int d : reach[c])
                            if (d != b && d != a && d != 1 && is[d][1])
                                ans = max(ans, val[a] + val[b] + val[c] + val[d]);
    cout << ans << endl;
    return;
}

signed main() {
    // freopen("holiday3.in", "r", stdin);
    // freopen("holiday.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}