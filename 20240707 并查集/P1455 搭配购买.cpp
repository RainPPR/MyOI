#include <bits/stdc++.h>

using namespace std;

struct pack01 {
    int n, v;
    vector<int> c, w;
    pack01() = delete;
    pack01(int v, vector<int> c, vector<int> w): n(c.size()), v(v), c(c), w(w), dp(v + 1) {}
    vector<int> dp;
    int calc() {
        for (int i = 0; i < n; ++i)
            for (int j = v; j >= c[i]; --j)
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        return dp[v];
    }
};

signed main() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> c(n + 1), w(n + 1), fa(n + 1);
    for (int i = 1; i <= n; ++i) cin >> c[i] >> w[i], fa[i] = i;
    // dsu
    function<int(int)> getfa = [&] (int x) {
        if (x == fa[x]) return x;
        return fa[x] = getfa(fa[x]);
    };
    auto unite = [&] (int x, int y) {
        x = getfa(x), y = getfa(y);
        if (x == y) return;
        fa[x] = y, c[y] += c[x], w[y] += w[x];
    };
    while (m--) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }
    vector<int> ct, wt;
    for (int i = 1; i <= n; ++i) {
        if (i != fa[i]) continue;
        ct.push_back(c[i]), wt.push_back(w[i]);
    }
    pack01 solev(v, ct, wt);
    cout << solev.calc() << endl;
    return 0;
}
