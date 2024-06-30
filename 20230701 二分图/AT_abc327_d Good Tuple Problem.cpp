#pragma GCC optimize("Ofast,fast-math")

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define endl '\n'

#ifdef __unix
#define getchar() getchar_unlocked()
#endif

#define rr read()
inline int read() {
    int n = 0, f = 0, c = getchar();
    #pragma GCC unroll 8
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    #pragma GCC unroll 8
    for (; isdigit(c); c = getchar()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

template<typename tp> inline tp Max(const tp a, const tp b) { return a > b ? a : b; }
template<typename tp> inline tp Min(const tp a, const tp b) { return a < b ? a : b; }
template<typename tp> inline tp Abs(const tp x) { return x < 0 ? -x : x; }

struct graph_t {
    int n, m; vector<vector<int>> g;
    graph_t() { g.clear(); }
    graph_t(int n): n(n) { g.resize(n + 1); }
    graph_t(int n, int m): n(n), m(m) { g.resize(n + 1); }
    void add(int u, int v) { g[u].push_back(v); }
    void Add(int u, int v) { add(u, v); add(v, u); }
};

struct {
    bool check(graph_t &e) {
        int n = e.n; vector<int> col(n + 1);
        function<bool(int, int)> dfs = [&] (int u, int c) {
            col[u] = c;
            #pragma GCC unroll 8
            for (int v : e.g[u]) {
                if (col[v] == c) return false;
                else if (col[v]) continue;
                if (!dfs(v, 3 - c)) return false;
            } return true;
        }; 
        #pragma GCC unroll 8
        rep(i, n) if (!col[i + 1] && !dfs(i + 1, 1)) return false;
        return true;
    }
} bi_graph;

signed main() {
    int n = rr, m = rr;
    vector<int> a(m), b(m);
    for (int &i : a) i = rr;
    for (int &i : b) i = rr;
    graph_t graph(n, m);
    rep(i, m) graph.Add(a[i], b[i]);
    printf(bi_graph.check(graph) ? "Yes\n" : "No\n");
    return 0;
}
