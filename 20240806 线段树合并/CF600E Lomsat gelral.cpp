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

using ll = long long;

#define int ll

constexpr int MAXN = 1e5;
constexpr int N = MAXN + 10;

int n;

vector<int> g[N];

int root[N], tot;

struct node {
    int lss, rss;
    struct vt {
        int cnt, ans;
        friend vt operator +(const vt &a, const vt &b) {
            if (a.cnt > b.cnt) return a;
            if (b.cnt > a.cnt) return b;
            return vt{a.cnt, a.ans + b.ans};
        }
    } v;
} a[int(5e6)];

void push_up(int k) {
    a[k].v = a[a[k].lss].v + a[a[k].rss].v;
}

void modify(int &k, int l, int r, int x, int v) {
    if (!k) k = ++tot;
    if (l == r) {
        a[k].v.ans = x;
        a[k].v.cnt += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        modify(a[k].lss, l, mid, x, v);
    else
        modify(a[k].rss, mid + 1, r, x, v);
    push_up(k);
}

int merge(int x, int y, int l, int r) {
    if (!x || !y) return x | y;
    if (l == r) {
        a[x].v.cnt += a[y].v.cnt;
        return x;
    }
    int mid = (l + r) >> 1;
    a[x].lss = merge(a[x].lss, a[y].lss, l, mid);
    a[x].rss = merge(a[x].rss, a[y].rss, mid + 1, r);
    push_up(x);
    return x;
}

int ans[N];

int get_ans(int root) {
    return a[root].v.ans;
}

void dfs(int u, int fa) {
    for (int v : g[u]) if (v != fa) {
        dfs(v, u);
        root[u] = merge(root[u], root[v], 1, MAXN);
    }
    ans[u] = get_ans(root[u]);
}

void Main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        root[i] = ++tot;
        int c;
        cin >> c;
        modify(root[i], 1, MAXN, c, 1);
    }
    for (int i = 2; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    copy_n(ans + 1, n, ostream_iterator<int>(cout, " "));
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