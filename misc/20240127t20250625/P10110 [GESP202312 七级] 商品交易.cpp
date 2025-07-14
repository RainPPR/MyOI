#include <bits/stdc++.h>

#define int ll
using ll = long long;

using namespace std;

constexpr int N = 1e5 + 10;
constexpr int M = 2e5 + 10;

int n, m, v[N];

vector<pair<int, int>> g[N];
#define add(u, v, w) g[u].push_back({v, w})

int dis[N], st[N];
int spfa(int a, int b) {
    memset(dis, 0x3f, sizeof dis); dis[a] = 0;
    queue<int> q; q.push(a); st[a] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        st[u] = false;
        for (auto [v, e] : g[u]) if (dis[v] > dis[u] + e) {
            dis[v] = dis[u] + e;
            if (!st[v]) q.push(v);
        }
    } return dis[b] >= 0x3f3f3f3f3f3f3f3f ? -1 : dis[b];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    int a, b, x, y, r;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) cin >> x >> y,add(x, y, v[y] - v[x] + 1);
    r = spfa(a, b);
    if (r == -1) puts("No solution");
    else cout << r << endl;
    return 0;
}