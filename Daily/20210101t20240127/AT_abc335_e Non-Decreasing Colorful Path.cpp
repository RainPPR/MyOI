#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) n = n * 10 + c - '0';
    return f ? -n : n;
}

signed main() {
    int n = rr, m = rr;
    vector<int> a(n);
    for (auto &i : a) i = rr;

    vector<int> fa(n); iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&] (int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); };
    auto merge = [&] (int a, int b) { fa[find(a)] = find(b); };

    vector<pii> edges(m);
    for (auto &[u, v] : edges) {
        u = rr - 1, v = rr - 1;
        if (a[u] == a[v]) merge(u, v);
        else if (a[u] > a[v]) swap(u, v);
    }

    vector<vector<int>> g(n);
    auto add_edge = [&] (int u, int v) { g[u].push_back(v); };

    for (auto &[u, v] : edges) {
        u = find(u), v = find(v);
        if (u == v) continue;
        add_edge(find(u), find(v));
    }

    vector<int> dp(n, -1e9); dp[find(n - 1)] = 1;
    function<int(int)> dfs = [&] (int u) -> int {
        if (dp[u] != -1e9) return dp[u];
        for (int v : g[u]) dp[u] = max(dp[u], dfs(v) + 1);
        return dp[u];
    };

    printf("%d\n", max(dfs(find(0)), 0));
    return 0;
}
