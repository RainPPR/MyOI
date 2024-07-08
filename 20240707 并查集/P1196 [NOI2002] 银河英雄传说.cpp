#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> fa, siz, d;
    dsu() = default;
    dsu(int n): fa(n), siz(n, 1), d(n) { iota(fa.begin(), fa.end(), 0); }
    int getfa(int x) {
        if (x == fa[x]) return x;
        int t = getfa(fa[x]);
        d[x] = d[x] + d[fa[x]];
        return fa[x] = t;
    }
    // merge x to y
    void unite(int x, int y) {
        x = getfa(x), y = getfa(y);
        fa[x] = y, d[x] = siz[y];
        siz[y] += siz[x];
    }
};

dsu a(30005);

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        char op[3];
        int x, y;
        cin >> op >> x >> y;
        if (op[0] == 'M') a.unite(x, y);
        else {
            if (a.getfa(x) != a.getfa(y)) cout << "-1" << endl;
            else cout << abs(a.d[x] - a.d[y]) - 1 << endl;
        }
    }
    return 0;
}