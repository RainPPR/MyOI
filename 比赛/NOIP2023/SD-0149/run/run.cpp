// rp++ what do your do at the end of the world?
// Y@2L32#
// T#YMS@4
// node: 0+998244710

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#ifdef __unix
#define getchar() getchar_unlocked()
#endif

#define endl '\n'
#define rr read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = getchar();
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

#define open(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(nullptr), cout.tie(nullptr)

template<typename tp> inline tp Max(const tp a, const tp b) { return a > b ? a : b; }
template<typename tp> inline tp Min(const tp a, const tp b) { return a < b ? a : b; }
template<typename tp> inline tp Abs(const tp a) { return a < 0 ? -a : a; }

#define chmin(a, x) ((a) = Min(a, x))
#define chmax(a, x) ((a) = Max(a, x))

int n, m, k, d;

struct cha {
    int y, v;
    cha() { y = v = 0; }
    cha(int y): y(y) {}
    cha(int y, int v): y(y), v(v) {}
    friend bool operator <(const cha &a, const cha &b) { return a.y < b.y; }
};

inline bool cmp_sort(const cha &a, const cha &b) { return a.v < b.v; }

unordered_set<int> app;
vector<vector<cha>> cr;

int getcha(int t, int cont) {
    auto &q = cr[t];
    auto it = upper_bound(q.begin(), q.end(), cha(cont));
    if (it == q.begin()) return 0;
    return (--it)->v;
}

ll res = -2e18;

// time(now), sum(value), continue(time)
void dfs(int t, ll v, int cont) {
    if (t == n + 1) return (void)(res = Max(res, v));
    int ad = getcha(t, cont);
    if (cont < k) dfs(t + 1, v + ad - d, cont + 1);
    dfs(t + 1, v + ad, 0);
}

ll solve() {
    n = rr, m = rr, k = rr, d = rr; cr.resize(n + 1);
    rep(_, m) {
        int x = rr, y = rr, v = rr;
        cr[x].push_back(cha(y, v));
        app.emplace(x);
    } for (int i : app) {
        auto &t = cr[i];
        sort(t.begin(), t.end(), cmp_sort);
        for (int i = 1; i < t.size(); ++i) t[i].v += t[i - 1].v;
        sort(t.begin(), t.end());
    } return (res = 0, dfs(0, 0, 0), res);
}

signed main() {
    open("run");
    int c = rr, t = rr;
    while (t--) printf("%lld\n", solve());
    return 0;
}
