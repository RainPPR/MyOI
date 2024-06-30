#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll INF = 4e18;

struct edge { int u, v; ll w; };

int n, m;
ll k;
vector<edge> g;

ll res = INF;

vector<int> used;

struct dsu {
    vector<int> f;
    dsu(int N) {
        f.resize(N + 1);
        for (int i = 1; i <= N; ++i)
        f[i] = i;
    } int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    } bool merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        f[b] = a; return true;
    }
};

bool doi() {
    dsu a(n); ll q = 0;
    for (int i : used) {
        edge e = g[i];
        if (!a.merge(e.u, e.v)) return false;
        q = (q + e.w) % k;
    } res = min(res, q);
    return true;
}

bool dfs(int k, int c) {
    if (c == n - 1) return doi();
    if (k == m) return false;
    used.push_back(k);
    dfs(k + 1,c + 1);
    used.pop_back();
    dfs(k + 1, c);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> k;
    g.resize(m);
    auto input = [] (edge &q) { cin >> q.u >> q.v >> q.w; };
    for (int i = 0; i < m; ++i) input(g[i]);
    dfs(0, 0);
    cout << res << endl;
    return 0;
}