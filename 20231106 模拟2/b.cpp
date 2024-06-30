#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

constexpr int N = 2e5 + 10;

struct node {
    int x, y;
}; vector<node> yin;

#define abs(x) _abs(x)
inline int _abs(int x) {
    return x < 0 ? -x : x;
}

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
    int u, v, lx, rx, ly, ry;
    scanf("%d%d%d%d%d%d", &u, &v, &lx, &rx, &ly, &ry);
    int r1 = 0, r2 = 0, r3 = 0; --u, --v;
    for (int x = lx; x <= rx; ++x) for (int y = ly; y <= ry; ++y) {
        int a = dist(yin[u].x, yin[u].y, x, y);
        int b = dist(yin[v].x, yin[v].y, x, y);
        if (a > b) ++r1;
        else if (a < b) ++r2;
        else ++r3;
    } printf("%d %d %d\n", r1, r2, r3);
}

signed main() {
    int n, q; scanf("%*d%d%d", &n, &q);
    yin.resize(n);
    rep(i, n) scanf("%d%d", &yin[i].x, &yin[i].y);
    while (q--) solve();
    return 0;
}
