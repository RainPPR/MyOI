#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

struct dsu {
    vector<int> fa, siz;
    dsu() = default;
    dsu(int n): fa(n), siz(n, 1) { iota(fa.begin(), fa.end(), 0); }
    int getfa(int x) {
        if (x == fa[x]) return x;
        return fa[x] = getfa(fa[x]);
    }
    void unite(int x, int y) {
        x = getfa(x), y = getfa(y);
        if (siz[x] > siz[y]) swap(x, y);
        fa[x] = y, siz[y] += siz[x];
    }
};

int n, m;

int getid(int x, int y) {
    return (x - 1) * n + y - 1 + 1;
}

int getfa(dsu &a, int x, int y) {
    return a.getfa(getid(x, y));
}

void unite(dsu &a, int x, int y, int i, int j) {
    a.unite(getid(x, y), getid(i, j));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    dsu a(n * n + 1);
    for (int k = 1; k <= m; ++k) {
        int x, y;
        char op[3];
        cin >> x >> y >> op;
        int i, j;
        if (op[0] == 'D')
            i = x + 1, j = y;
        else
            i = x, j = y + 1;
        if (getfa(a, i, j) == getfa(a, x, y)) {
            cout << k << endl;
            exit(0);
        }
        unite(a, i, j, x, y);
    }
    cout << "draw" << endl;
    return 0;
}