#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using LL = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

struct edge {
    int u, v, w;
    friend bool operator <(const edge &a, const edge &b) {
        return a.w > b.w;
    }
};

struct query {
    int x, p;
    friend bool operator <(const query &a, const query &b) {
        return a.x > b.x;
    }
};

signed DOI() {
    int n = rr, m = rr, q = rr;

    ll qin = 2e9, all = 0;
    vector<int> a(n);
    rep(i, n) a[i] = rr, qin = min(qin, a[i]), all += a[i];

    vector<edge> g(m);
    rep(i, m) g[i] = {rr - 1, rr - 1, 0}, g[i].w = rr;
    sort(g.begin(), g.end());

    vector<query> e(q);
    rep(i, q) e[i]= {rr, i};
    sort(e.begin(), e.end());

    int cnt = n;
    vector<int> f(n), v(n);
    rep(i, n) f[i] = i, v[i] = a[i];

    function<int(int)> find = [&] (int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }; auto merge = [&] (int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        --cnt; f[y] = x;
        all -= max(v[x], v[y]);
        v[x] = min(v[x], v[y]);
    };

    vector<ll> ans(q);
    int j = 0; for (query t : e) {
        for (; j < m && g[j].w >= t.x; ++j) merge(g[j].u, g[j].v);
        ans[t.p] = 1ll * qin * (cnt - 1) + all - qin;
    }

    rep(i, q) printf("%lld\n", ans[i]);
    return 114514;
}

signed main() {
    freopen("add.in", "r", stdin);
    freopen("add.out", "w", stdout);
    do { DOI(); } while (false);
    return 0;
}
