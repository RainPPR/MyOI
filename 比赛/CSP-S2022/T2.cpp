#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

constexpr int N = 1e5 + 10;

struct marray {
    int n, a[N];
    
    int st_max[20][N], st_min[20][N];
    int st_geq[20][N], st_leq[20][N];

    void init() {
        for (int i = 1; i <= n; ++i) {
            st_max[0][i] = st_min[0][i] = a[i];
            if (a[i] == 0)
                st_geq[0][i] = st_leq[0][i] = 0;
            else if (a[i] > 0)
                st_geq[0][i] = a[i], st_leq[0][i] = -2e9;
            else
                st_leq[0][i] = a[i], st_geq[0][i] = 2e9;
        }
        for (int k = 1; k < 20; ++k)
            for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
                st_max[k][i] = max(st_max[k - 1][i], st_max[k - 1][i + (1 << (k - 1))]);
                st_min[k][i] = min(st_min[k - 1][i], st_min[k - 1][i + (1 << (k - 1))]);
                st_leq[k][i] = max(st_leq[k - 1][i], st_leq[k - 1][i + (1 << (k - 1))]);
                st_geq[k][i] = min(st_geq[k - 1][i], st_geq[k - 1][i + (1 << (k - 1))]);
            }
    }

    int get_st(decltype(st_max) st, int l, int r, function<int(int, int)> op) {
        int k = __lg(r - l + 1);
        return op(st[k][l], st[k][r - (1 << k) + 1]);
    }

    int get_max(int l, int r) {
        return get_st(st_max, l, r, [] (int x, int y) {
            return max(x, y);
        });
    }

    int get_min(int l, int r) {
        return get_st(st_min, l, r, [] (int x, int y) {
            return min(x, y);
        });
    }

    int get_geq(int l, int r) {
        return get_st(st_geq, l, r, [] (int x, int y) {
            return min(x, y);
        });
    }

    int get_leq(int l, int r) {
        return get_st(st_leq, l, r, [] (int x, int y) {
            return max(x, y);
        });
    }
} a, b;

void Main() {
    int q;
    cin >> a.n >> b.n >> q;
    for (int i = 1; i <= a.n; ++i)
        cin >> a.a[i];
    a.init();
    for (int i = 1; i <= b.n; ++i)
        cin >> b.a[i];
    b.init();
    // a.debug();
    // b.debug();
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll res = 0;
        if (b.get_min(l2, r2) > 0)
            res = min(1ll * a.get_max(l1, r1) * b.get_min(l2, r2), 1ll * a.get_max(l1, r1) * b.get_max(l2, r2));
        else if (b.get_max(l2, r2) < 0)
            res = min(1ll * a.get_min(l1, r1) * b.get_max(l2, r2), 1ll * a.get_min(l1, r1) * b.get_min(l2, r2));
        else if (a.get_min(l1, r1) > 0)
            res = 1ll * a.get_min(l1, r1) * b.get_min(l2, r2);
        else if (a.get_max(l1, r1) < 0)
            res = 1ll * a.get_max(l1, r1) * b.get_max(l2, r2);
        else
            res = max(1ll * a.get_geq(l1, r1) * b.get_min(l2, r2),1ll * a.get_leq(l1, r1) * b.get_max(l2, r2));
        cout << res << endl;
    }
    return;
}

signed main() {
    // freopen("game.in", "r", stdin);
    // freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}