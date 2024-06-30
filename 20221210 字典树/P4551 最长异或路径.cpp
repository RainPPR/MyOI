#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

#define rep(i, n) for (decltype(n) i = 0; i < (n); ++i)
#define gor(i, l, r) for (decltype(r) i = (l); i < (r); ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

signed main() {
    int n = rr;
    vector<vector<pii>> g(n);
    auto add = [&] (int u, int v, int w) { g[u].push_back({v, w}); };
    auto Add = [&] (int u, int v, int w) { add(u, v, w); add(v, u, w); };
    auto getedge = [&] () { int u = rr - 1, v = rr - 1; Add(u, v, rr); };
    rep(i, n - 1) getedge();
    constexpr int root = 1;
    vector<int> fr(n); // w[root] ^ .. ^ w[x]
    function<void(int, int)> dfs1 = [&] (int u, int fa) {
        for (auto i : g[u]) if (i.first != fa) {
            auto &v = i.first, &w = i.second;
            fr[v] = fr[u] ^ w; dfs1(v, u);
        } return (void)("rp++");
    }; dfs1((fr[root] = 0, root), -1);
    struct Trie {
        vector<array<int, 2>> ch; int idx;
        function<void(int)> insert = [&] (int x) {
            int root = 0; for (int k = 30; ~k; --k) {
                int pos = (x >> k) & 1;
                if (!ch[root][pos]) ch[root][pos] = ++idx;
                root = ch[root][pos];
            } return (void)("rp++");
        }; function<int(int)> query = [&] (int x) {
            int root = 0, r = 0; for (int k = 30; ~k; --k) {
                int pos = (x >> k) & 1;
                if (ch[root][pos ^ 1]) root = ch[root][pos ^ 1], r |= 1 << k;
                else if (ch[root][pos]) root = ch[root][pos];
                else throw("UNKNOWN ERROR");
            } return r;
        }; Trie(int N) { idx = 0, ch.resize(N); }
    } trie(n * 31 + 5); for (int i : fr) trie.insert(i);
    int ans = 0; for (int i : fr) ans = max(ans, trie.query(i));
    printf("%d\n", ans);
    return 0;
}
