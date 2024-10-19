#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1
#define D(x) ({ void(0); })
#else
#define D(x) ({ cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << (x) << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

// -----------------------------------------------------------------------------

// constexpr int N = 5e4 + 10;
constexpr int N = 1e5 + 10;
constexpr int M = 1e5 + 10;

// -----------------------------------------------------------------------------

int n, m;
int col[N];

struct edge {
    int v, w;
    edge() = default;
    edge(int v, int w): v(v), w(w) {}
};

vector<edge> g[N];

// -----------------------------------------------------------------------------

int fa[N], siz[N];
int son[N], dep[N];

int dfs[2 * N], tot;
int st[N], ed[N];

void dfs1(int u, int ff) {
    dfs[++tot] = u;
    st[u] = tot;
    son[u] = -1;
    siz[u] = 1;
    int mx = -1;
    for (auto t : g[u]) {
        int v = t.v;
        if (v == ff) continue;
        col[v] = t.w;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > mx) {
            mx = siz[v];
            son[u] = v;
        }
    }
    dfs[++tot] = u, ed[u] = tot;
}

int top[N];

void dfs2(int u, int to) {
    top[u] = to;
    if (son[u] == -1) return;
    dfs2(son[u], to);
    for (auto t : g[u]) {
        int v = t.v;
        if (v == fa[u]) continue;
        if (v == son[u]) continue;
        dfs2(v, v);
    }
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]]) x = fa[top[x]];
        else y = fa[top[y]];
    }
    if (dep[x] > dep[y]) return y;
    return x;
}

// -----------------------------------------------------------------------------

int block, belong[2 * N];

struct query {
    int id, l, r, lca;
    friend bool operator <(const query &a, const query &b) {
        if (belong[a.l] != belong[b.l]) return a.l < b.l;
        return belong[a.l] & 1 ? a.r < b.r : a.r > b.r;
    }
} Q[M];

// -----------------------------------------------------------------------------

struct ans {
    int val;
    bool ft;
    ans(): val(0), ft(0) {}
    ans(int val): val(val), ft(0) {}
    ans(double val): val(int(val)), ft(val - int(val) != 0) {}
    friend ostream& operator <<(ostream &out, const ans &x) {
        out << x.val << (x.ft ? ".5" : ".0");
        return out;
    }
} Ans[M];

constexpr int MAXV = 1e5;
constexpr int V = MAXV + 10;

int block2, belong2[V];
int cnt2, L[V], R[V];

void init2() {
    block2 = sqrt(MAXV);
    cnt2 = (MAXV - 1) / block2 + 1;
    for (int i = 1; i <= MAXV; ++i)
        belong2[i] = (i - 1) / block2 + 1;
    for (int i = 1; i <= cnt2; ++i)
        R[i] = i * block2, L[i] = R[i] - block2 + 1;
    R[cnt2] = V;
}

int arr[V], sum[V];

void modify(int x, int v) {
    arr[x] += v;
    sum[belong2[x]] += v;
}

int rnk(int k) {
    int inner = 1;
    while (sum[inner] < k)
        k -= sum[inner], ++inner;
    for (int i = L[inner]; i <= R[inner]; ++i) {
        k -= arr[i];
        if (k <= 0) return i;
    }
    __builtin_unreachable();
}

int cnt;

void add(int x) {
    ++cnt;
    modify(x, 1);
}

void del(int x) {
    --cnt;
    modify(x, -1);
}

ans get_ans() {
    if (cnt & 1)
        return rnk((cnt + 1) >> 1);
    return (rnk((cnt >> 1) + 1) + rnk(cnt >> 1)) / 2.0;
}

int vis[2 * N];

void calc(int x) {
    if (vis[x])
        del(col[x]);
    else
        add(col[x]);
    vis[x] ^= 1;
}

// -----------------------------------------------------------------------------

void clear() {
    memset(arr, 0, sizeof arr);
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= n; ++i)
        g[i].clear(), g[i].shrink_to_fit();
    cnt = tot = dep[1] = 0;
    memset(vis, 0, sizeof(int) * n * 2);
}

void Main() {
    cin >> n;
    clear();
    for (int i = 2; i <= n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs1(1, -1);
    dfs2(1, 1);
    col[1] = 1;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        if (st[x] > st[y]) swap(x, y);
        int l = lca(x, y);
        if (x == l) Q[i] = {i, st[x], st[y], l};
        else Q[i] = {i, ed[x], st[y], -1};
    }
    block = max(1, int(tot / sqrt(m * 2.0 / 3)));
    for (int i = 1; i <= tot; ++i)
        belong[i] = (i - 1) / block + 1;
    sort(Q + 1, Q + m + 1);
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
        int x = Q[i].l, y = Q[i].r;
        if (x == y) {
            Ans[Q[i].id] = col[dfs[x]];
            continue;
        }
        while (x < l) calc(dfs[--l]);
        while (y > r) calc(dfs[++r]);
        while (x > l) calc(dfs[l++]);
        while (y < r) calc(dfs[r--]);
        if (Q[i].lca != -1) calc(Q[i].lca);
        Ans[Q[i].id] = get_ans();
        if (Q[i].lca != -1) calc(Q[i].lca);
    }
    for (int i = 1; i <= m; ++i) {
        cout << Ans[i] << endl;
    }
}

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    init2();
    int T;
    cin >> T;
    while (T--)
        Main();
    return 0;
}