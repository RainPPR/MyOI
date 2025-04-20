#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = (l); i < (r); ++i)
#define xin(i, a) for (auto i : a)

#define gc() getchar_unlocked()
#define endl '\n'

#define ri read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

// here?


signed main() {
    int n = ri, q = ri;

    vector<vector<int>> g(n + 1);
    auto add = [&] (int u, int v) { g[u].push_back(v), g[v].push_back(u); };
    rep(i, n - 1) add(ri, ri);

    vector<int> dep(n + 1), from(n + 1);
    function<void(int, int)> build = [&] (int u, int fa) {
        from[u] = fa, dep[u] = dep[fa] + 1;
        xin(v, g[u]) if (v != fa) build(v, u);
    };
    
    vector<int> f(n + 1), sz(n + 1);
    gor(i, 1, n + 1) f[i] = i, sz[i] = 1;
    function<int(int)> find = [&] (int x) { return x == f[x] ? x : f[x] = find(f[x]); };
    auto merge = [&] (int a, int b) { a = find(a), b = find(b); if (a != b) f[a] = b, sz[b] += sz[a]; };
    auto goup = [&] (int &a) { merge(a, from[a]), a = from[a]; };

    build(1, 0);
    auto mlist = [&] (int a, int b) {
        if (dep[a] < dep[b]) swap(a, b);
        while (dep[a] > dep[b]) goup(a);
        while (a != b) goup(a), goup(b);
    }; while (q--) mlist(ri, ri);

    // vector<int> e;
    // gor(i, 1, n + 1) if (i == f[i]) e.push_back(sz[i]);

    // unordered_set<int> r;
    // r.emplace(e[0]);
    // gor(i, 1, e.size()) {
    //     auto bak = r; r.clear();
    //     xin(j, bak) r.emplace(j + e[i]), r.emplace(j - e[i]);
    // }

    // vector<int> t(r.size());
    // int c = 0; xin(i, r) t[c++] = abs(i);
    // sort(t.begin(), t.end());
    // for (auto i : t) printf("%d ", i);
    return 0;
}
