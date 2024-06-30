#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read<int>()
#define ur uread<int>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = n * 10 + c - '0';
    return f ? -n : n;
}

template<typename tp>
inline tp uread() {
    tp n = 0; int c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

signed main() {
    int n = rr, x = rr, y = rr;
    vector<vector<int>> g(n + 1);
    vector<int> fa(n + 1), dep(n + 1);
    rep(i, n - 1) { int u = rr, v = rr; g[u].push_back(v); g[v].push_back(u); }
    function<void(int, int)> build = [&] (int u, int f) {
        for (int &v : g[u]) if (v != f)
        build((dep[v] = dep[u] + 1, fa[v] = u, v), u);
    }; dep[1] = 1; build(1, -1); vector<int> lans, rans;
    while (dep[x] > dep[y]) lans.push_back(x), x = fa[x];
    while (dep[y] > dep[x]) rans.push_back(y), y = fa[y];
    while (x != y) lans.push_back(x), rans.push_back(y), x = fa[x], y = fa[y];
    rep(i, lans.size()) printf("%d ", lans[i]);
    printf("%d ", x);
    rep(i, rans.size()) printf("%d ", rans[rans.size() - i - 1]);
    return 0;
}