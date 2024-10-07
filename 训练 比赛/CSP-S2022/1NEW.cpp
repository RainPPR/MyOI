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

        if (u != s) {
            is[s][u] = 1;
            reach[s].push_back(u);
        }

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

vector<pair<ll, int>> pos[N];

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
    for (int a : reach[1])
        for (int b : reach[a])
            if (a != b && b != 1)
                pos[b].emplace_back(val[a] + val[b], a);
    for (int i = 1; i <= n; ++i)
        sort(pos[i].begin(), pos[i].end(), greater<>());
    ll ans = -1;
    for (int a = 2; a <= n; ++a)
        for (int b : reach[a])
            if (a != b && b != 1)
                for (int i = 0; i < 3 && i < pos[a].size(); ++i)
                    if (pos[a][i].second != a && pos[a][i].second != b)
                        for (int j = 0; j < 3 && j < pos[b].size(); ++j)
                            if (pos[b][j].second != a && pos[b][j].second != b && pos[b][j].second != pos[a][i].second)
                                ans = max(ans, pos[a][i].first + pos[b][j].first);
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