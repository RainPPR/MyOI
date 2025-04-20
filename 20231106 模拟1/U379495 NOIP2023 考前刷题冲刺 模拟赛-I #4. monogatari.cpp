#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

#define endl '\n'
#define gc() getchar_unlocked()

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return n;
}

using ll = long long;

const int N = 3e5 + 10;

int n, zero;
int p[N];

vector<int> g[N];
void add(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

int depth[N], tag[N]; ll sum[N];
void dfs(int u, int fa, int tg) {
    depth[u] = depth[fa] + 1;
    sum[u] = sum[fa] + p[u];
    tag[u] = tg; for (int v : g[u])
        if (v != fa) dfs(v, u, tg);
}

ll solve() {
    depth[zero] = 0, sum[zero] = p[zero], tag[zero] = -1;
    for (int i : g[zero]) dfs(i, zero, i);
    ll res = 0;
    rep(i, n) rep(j, i) if (tag[i] != tag[j]) {
        ll s = sum[i] + sum[j] - sum[zero];
        ll l = depth[i] + depth[j] + 1;
        if (s == l * (l - 1) / 2) ++res;
    } return res + 1;
}

signed main() {
    n = rr, zero = -1;
    rep(i, n) {
        p[i] = rr;
        if (!p[i]) zero = i;
    } rep(i, n - 1) add(rr - 1, rr - 1);
    int m = rr;
    while (m--) {
        int x = rr - 1, y = rr - 1;
        swap(p[x], p[y]);
        if (!p[x]) zero = x;
        if (!p[y]) zero = y;
        printf("%lld\n", solve());
    } return 0;
}
