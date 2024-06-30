#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using fvi = function<void(int)>;
using fii = function<int(int)>;

#define rep(int, i, n) for (int i = 0; i < int(n); ++i)
#define gor(int, i, l, r) for (int i = int(l); i < int(r); ++i)
#define xin(i, x) for (auto i : x)

#define endl '\n'
#define gc() getchar_unlocked()

#define ri() read<int>()
#define rl() read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

constexpr int INF = 1e9;

signed main() {
    int n = ri();
    vector<vi> g(n);
    vi fa(n), a(n), b(n);
    gor(int, _, 1, n) {
        fa[_] = ri() - 1;
        g[fa[_]].push_back(_);
        a[_] = ri(), b[_] = ri();
    } fa[0] = -1; vi dep(n), f(n, INF);
    fvi dfs = [&] (int u) {
        if (u == 0) f[u] = 0;
        else {
            int v = u;
            while ((v = fa[v]) != -1)
            f[u] = min(f[u], b[u] + a[u] * dep[u] + f[v] - a[u] * dep[v]);
        } xin(v, g[u])
        dep[v] = dep[u] + 1, dfs(v);
    }; dfs(0); 
    rep(int, i, n) printf("%d ", f[i]);
    return 0;
}
