#pragma GCC optimize(1,2,"Ofast,fast-math")
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define endl '\n'
#define gc() getchar_unlocked()

#define rr uread<unsigned>()

template<typename tp>
inline tp uread() {
    tp n = 0; int c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

int n;

vector<vector<int>> g;

void add(int u, int v) {
    g[u].push_back(v);
}

void Add(int u, int v) {
    add(u, v); add(v, u);
}

vector<int> sz;

int build(int u, int fa) {
    sz[u] = 1;
    for (int &v : g[u]) if (v != fa) sz[u] += build(v, u);
    return sz[u];
}

signed main() {
    g.resize((n = rr) + 1);
    rep(i, n - 1) Add(rr, rr);
    sz.resize(n + 1);
    int s = build(1, -1), x = s;
    for (int &k : g[1]) x = min(x, s - sz[k]);
    printf("%d\n", x);
    return 0;
}
