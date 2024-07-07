#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> fa;
    dsu(int siz): fa(siz) { iota(fa.begin(), fa.end(), 0); }
    int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
    void unite(int x, int y) { fa[getfa(x)] = getfa(y); }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    dsu a(2 * n + 1);
    while (m--) {
        char op[3];
        int x, y;
        cin >> op >> x >> y;
        if (op[0] == 'F') a.unite(x, y);
        else a.unite(x + n, y), a.unite(y + n, x);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += a.fa[i] == i;
    cout << res << endl;
    return 0;
}