#define NDEBUG 1

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 1e5 + 10;

// -----------------------------------------------------------------------------

int n, m;

struct edge {
    int v, w;
    edge() = default;
    edge(int v, int w): v(v), w(w) {}
};

vector<edge> g[N];

int col[N];

// -----------------------------------------------------------------------------

int dfs[2 * N], tot;
int st[N], ed[N];

namespace hld {
    int fa[N], son[N];
    int dep[N], siz[N];
    int top[N];

    void dfs1(int u, int ff) {
        dfs[++tot] = u, st[u] = tot;
        siz[u] = 1, son[u] = -1;
        int mx = -1;
        for (auto t : g[u]) {
            int v = t.v;
            if (v == ff) continue;
            col[v] = t.w;
            fa[v] = u, dep[v] = dep[u] + 1;
            dfs1(v, u), siz[u] += siz[v];
            if (siz[v] > mx) mx = siz[v], son[u] = v;
        }
        dfs[++tot] = u, ed[u] = tot;
    }

    void dfs2(int u, int tp) {
        top[u] = tp;
        if (son[u] == -1) return;
        dfs2(son[u], tp);
        for (auto t : g[u]) {
            if (t.v == fa[u]) continue;
            if (t.v == son[u]) continue;
            dfs2(t.v, t.v);
        }
    }
}

int lca(int u, int v) {
    while (hld::top[u] != hld::top[v]) {
        if (hld::dep[hld::top[u]] > hld::dep[hld::top[v]])
            u = hld::fa[hld::top[u]];
        else v = hld::fa[hld::top[v]];
    }
    return hld::dep[u] < hld::dep[v] ? u : v;
}

// -----------------------------------------------------------------------------

int block1, belong1[2 * N];

struct query {
    int id, l, r, lca;
    friend bool operator <(const query &a, const query &b) {
        if (belong1[a.l] != belong1[b.l]) return a.l < b.l;
        return belong1[a.l] & 1 ? a.r < b.r : a.r > b.r;
    }
} q[N];

// -----------------------------------------------------------------------------

bool vis[2 * N];

int block, cnt;
int belong[N], L[N], R[N];
int bucket[N], appr[N];

void add(int x) {
    ++x;
    if (x > n) return;
    if (!bucket[x]) ++appr[belong[x]];
    ++bucket[x];
}

void del(int x) {
    ++x;
    if (x > n) return;
    --bucket[x];
    if (!bucket[x]) --appr[belong[x]];
}

int get_ans() {
    int inner = 1;
    while (inner <= cnt && appr[inner] == R[inner] - L[inner] + 1) ++inner;
    for (int i = L[inner]; i <= R[inner]; ++i) if (!bucket[i]) return i - 1;
    __builtin_unreachable();
    return 0;
}

void calc(int x) {
    if (vis[x]) del(col[x]);
    else add(col[x]);
    vis[x] ^= 1;
}

// -----------------------------------------------------------------------------

int ans[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    // ???????
    block = sqrt(n), cnt = (n - 1) / block + 1;
    for (int i = 1; i <= n; ++i) belong[i] = (i - 1) / block + 1;
    for (int i = 1; i <= cnt; ++i) R[i] = i * block, L[i] = R[i] - block + 1;
    R[cnt] = n;
    // ????
    for (int i = 2; i <= n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    // ?????
    hld::dfs1(1, -1);
    hld::dfs2(1, 1);
    col[1] = 1;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if (st[u] > st[v]) swap(u, v);
        int l = lca(u, v);
        if (l == u) q[i] = query{i, st[u], st[v], l};
        else q[i] = query{i, ed[u], st[v], -1};
    }
    block1 = max(1, int(tot / sqrt(m * 2 / 3.0)));
    for (int i = 1; i <= tot; ++i) belong1[i] = (i - 1) / block1 + 1;
    sort(q + 1, q + m + 1);
    // ????
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
        int x = q[i].l, y = q[i].r;
        while (x < l) calc(dfs[--l]);
        while (y > r) calc(dfs[++r]);
        while (x > l) calc(dfs[l++]);
        while (y < r) calc(dfs[r--]);
        if (q[i].lca != -1) calc(q[i].lca);
        ans[q[i].id] = get_ans();
        if (q[i].lca != -1) calc(q[i].lca);
    }
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << endl;
    return 0;
}