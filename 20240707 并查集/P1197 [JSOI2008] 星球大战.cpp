#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 4e5 + 10;

int n, m;

int hack[N];
bool hacked[N];

vector<int> g[N];

int fa[N], tot;

int getfa(int x) {
    if (x == fa[x]) return x;
    return fa[x] = getfa(fa[x]);
}

void unite(int x, int y) {
    x = getfa(x), y = getfa(y);
    if (x != y) fa[x] = y, --tot;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    tot = n;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ++u, ++v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> hack[i];
        hacked[++hack[i]] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (hacked[i]) continue;
        if (!g[i].empty())
        for (int j : g[i]) {
            if (hacked[j]) continue;
            unite(i, j);
        }
    }
    vector<int> ans(k + 1);
    ans[k] = tot - k;
    for (int i = k - 1; ~i; --i) {
        int x = hack[i];
        hacked[x] = 0;
        if (!g[x].empty())
        for (int y : g[x]) {
            if (hacked[y]) continue;
            unite(x, y);
        }
        ans[i] = tot - i;
    }
    for (int i : ans)
        cout << i << endl;
    return 0;
}