#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1
#define D(x) ({ void(0); })
#else
#define D(x) ({ auto t = (x); cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << t << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

// -----------------------------------------------------------------------------

constexpr int N = 1e5 + 10;

// -----------------------------------------------------------------------------

int n, m;

vector<int> g[N];

int dep[N], fa[N];
int siz[N], son[N];

void dfs1(int u, int ff) {
    siz[u] = 1;
    son[u] = -1;
    int mx = -1;
    for (int v : g[u]) {
        if (v == ff)
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > mx) {
            mx = siz[v];
            son[u] = v;
        }
    }
}

int top[N];

void dfs2(int u, int tp) {
    top[u] = tp;
    if (son[u] == -1)
        return;
    dfs2(son[u], tp);
    for (int v : g[u]) {
        if (v == fa[u])
            continue;
        if (v == son[u])
            continue;
        dfs2(v, v);
    }
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]])
            x = fa[top[x]];
        else
            y = fa[top[y]];
    }
    if (dep[x] < dep[y])
        return x;
    return y;
}

// -----------------------------------------------------------------------------

int root[N];

struct node {
    int lss, rss;
    int v, mx;
};

int tot;

vector<node> a(1);

int new_node() {
    a.push_back(node());
    return ++tot;
}

void push_up(int k) {
    if (a[a[k].lss].v > a[a[k].rss].v)
        a[k].v = a[a[k].lss].v, a[k].mx = a[a[k].lss].mx;
    else
        a[k].v = a[a[k].rss].v, a[k].mx = a[a[k].rss].mx;
}

void modify(int &k, int l, int r, int x, int v) {
    if (!k) k = new_node();
    if (l == r) {
        a[k].v += v;
        a[k].mx = l;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(a[k].lss, l, mid, x, v);
    else modify(a[k].rss, mid + 1, r, x, v);
    push_up(k);
}


int merge(int x, int y, int l, int r) {
    if (!x || !y) return x + y;
    if (l == r) {
        a[x].v += a[y].v;
        return x;
    }
    int mid = (l + r) >> 1;
    a[x].lss = merge(a[x].lss, a[y].lss, l, mid);
    a[x].rss = merge(a[x].rss, a[y].rss, mid + 1, r);
    return push_up(x), x;
}

void Debug(int root, ostream &out = cerr, int l = 1, int r = 1e5) {
    if (l == r) {
        if (l <= 5)
            out << "| DEBUG " << l << ": " << a[root].v << endl;
        return;
    }
    int mid = (l + r) >> 1;
    Debug(a[root].lss, out, l, mid);
    Debug(a[root].rss, out, mid + 1, r);
}

#define merge(x, y) merge(x, y, 1, (int)1e5)
#define modify(k, x, v) modify(k, 1, (int)1e5, x, v)
#define get_ans(k) a[k].v

// -----------------------------------------------------------------------------

int ans[N];

void dfs(int u) {
    for (int v : g[u])
        if (v != fa[u]) {
            dfs(v);
            //root[u] = merge(root[u], root[v]);
        }
    cerr << "| ROOT = " << u << endl;
    Debug(root[u], cerr);
    ans[u] = get_ans(root[u]);
}

// -----------------------------------------------------------------------------

void Main() {
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, -1), dfs2(1, 1);
    for (int i = 1; i <= n; ++i)
        root[i] = new_node();
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (dep[u] > dep[v])
            swap(u, v);
        int l = lca(u, v);
        if (u == l) {
            modify(root[v], w, 1);
            if (fa[u])
                modify(root[fa[u]], w, -1);
        }
        else {
            modify(root[u], w, 1);
            modify(root[v], w, 1);
            modify(root[l], w, -1);
            if (fa[l])
                modify(root[fa[l]], w, -1);
        }
    }
    dfs(1);
    copy_n(ans + 1, n, ostream_iterator<int>(cout, "\n"));
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    Main();
    return 0;
}