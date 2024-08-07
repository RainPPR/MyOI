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

#define int ll

using ll = long long;

constexpr int N = 3e5 + 10;
constexpr int INF = 2e9;

int n, col[N];

int fa[N], fs[N], fsfs[N];

vector<int> g[N];

int first_son(int x) {
    if (x == -1)
        return -1;
    for (int y : g[x])
        if (y != fa[x])
            return y;
    return -1;
}

namespace sdfs {
    int colx[N];
    int st[N], ed[N], tot;

    void dfs(int u, int ff) {
        colx[++tot] = col[u];
        st[u] = tot;
        fs[u] = fsfs[u] = -1;
        bool flag1 = true;
        bool flag2 = true;
        for (int v : g[u]) {
            if (v == ff)
                continue;
            if (flag1) {
                fs[u] = v;
                flag1 = false;
            }
            fa[v] = fa[u] + 1;
            dfs(v, u);
            if (flag2 && fs[v] != -1) {
                fsfs[u] = fs[v];
                flag2 = false;
            }
        }
        ed[u] = tot;
    }

    int table[20][N];

    void init() {
        dfs(1, -1);
        assert(tot == n);
        for (int i = 1; i <= n; ++i)
            table[0][i] = colx[i];
        for (int k = 1; k < 20; ++k)
            for (int i = 1; i + (1 << k) - 1 <= n; ++i)
                table[k][i] = max(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
    }

    int rmq(int l, int r) {
        if (l > r) return -INF;
        int k = __lg(r - l + 1);
        return max(table[k][l], table[k][r - (1 << k) + 1]);
    }

    int rmq1(int x) {
        if (x == 1) return -INF;
        return max(rmq(st[fa[x]] + 1, st[x] - 1), rmq(ed[x] + 1, ed[fa[x]]));
    }

    int rmq2(int x) {
        if (x == 1) return -INF;
        return max(rmq(1, st[fa[x]] - 1), rmq(ed[fa[x]] + 1, tot));
    }
}

namespace sbfs {
    int colx[N];
    int pos[N], tot;
    int vis[N];

    void init() {
        queue<int> q;
        memset(vis, 0, sizeof(int) * (n + 1));
        q.push(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 1;
            colx[++tot] = col[u];
            pos[u] = tot;
            for (int v : g[u]) {
                if (vis[v])
                    continue;
                q.push(v);
            }
        }
        assert(tot == n);
        for (int i = n - 1; i; --i)
            colx[i] = max(colx[i], colx[i + 1]);
    }

    int rmq1(int x) {
        x = fsfs[x];
        if (x == -1) return -INF;
        return colx[pos[x]];
    }
}

int Main() {
    cin >> n;
    int ans = INF;
    for (int i = 1; i <= n; ++i)
        cin >> col[i];
    for (int i = 2; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    sdfs::init();
    sbfs::init();
    for (int i = 1; i <= n; ++i) {
       // D(i);
        int res = col[i];
        for (int j : g[i]) res = max(res, col[j] + 1);
       // D(res);
        int b1 = sbfs::rmq1(i) + 2;
       // D(b1);
        int b2 = sdfs::rmq1(i) + 2;
       // D(b2);
        int b3 = sdfs::rmq2(i) + 2;
       // D(b3);
        ans = min(ans, max({res, b1, b2, b3}));
       // D("-----------------------");
    }
    return ans;
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    cout << Main() << endl;
    return 0;
}