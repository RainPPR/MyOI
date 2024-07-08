#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

struct dsu {
    vector<int> fa, d;
    dsu() = default;
    dsu(int siz): fa(siz), d(siz) { iota(fa.begin(), fa.end(), 0); }
    int getfa(int x) {
        if (x == fa[x]) return x;
        int t = getfa(fa[x]);
        d[x] = d[x] + d[fa[x]];
        return fa[x] = t;
    }
};

int n, k;

dsu a;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    a = dsu(n + 1);
    auto uni = [] (int x, int y) -> bool {
        int px = a.getfa(x);
        int py = a.getfa(y);
        if (px != py) {
            a.fa[px] = py;
            a.d[px] = a.d[y] - a.d[x];
            return true;
        }
        return ((a.d[x] - a.d[y]) % 3 + 3) % 3 == 0;
    };
    auto eat = [] (int x, int y) -> bool {
        int px = a.getfa(x);
        int py = a.getfa(y);
        if (px != py) {
            a.fa[px] = py;
            a.d[px] = a.d[y] - a.d[x] + 1;
            return true;
        }
        return ((a.d[x] - a.d[y]) % 3 + 3) % 3 == 1;
    };
    int ans = 0;
    while (k--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (x > n || y > n) ++ans;
        else if (op == 1) ans += !uni(x, y);
        else if (op == 2) ans += !eat(x, y);
    }
    cout << ans << endl;
    return 0;
}