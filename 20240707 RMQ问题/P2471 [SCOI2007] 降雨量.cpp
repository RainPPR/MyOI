#include <bits/stdc++.h>

using namespace std;

struct node {
    int year, rain;
    node() = default;
    node(int d): year(d), rain(0) {}
    node(int d, int r): year(d), rain(r) {}
    friend bool operator <(const node &a, const node &b) {
        return a.year < b.year;
    }
};

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<node> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].year >> a[i].rain, a[i].year += 1e9;
    auto maxr = [&] (int l, int r) {
        int e = -1;
        for (int i = l; i <= r; ++i)
            //cout << "  GET " << a[i].year << " " << a[i].rain << endl,
            e = max(e, a[i].rain);
        return e;
    };
    int t; cin >> t;
    while (t--) {
        int y, x;
        cin >> y >> x;
        x += 1e9, y += 1e9;
        auto l = lower_bound(a.begin(), a.end(), node(y));
        auto r = lower_bound(a.begin(), a.end(), node(x));
        int dl = l->rain, dr = r->rain;
        int cl = l != a.end() && l->year == y;
        int cr = r != a.end() && r->year == x;
        int st = (cl << 1) | cr;
        if (st == 0b11) {
            int in = maxr(l - a.begin() + 1, r - a.begin() - 1);
            if (dr > dl || in >= dr) puts("false");
            else if (r - l == x - y) puts("true");
            else puts("maybe");
        } else if (st == 0b10) {
            int in = maxr(l - a.begin() + 1, r - a.begin() - 1);
            if (in >= dl) puts("false");
            else puts("maybe");
        } else if (st == 0b01) {
            int in = maxr(l - a.begin(), r - a.begin() - 1);
            if (in >= dr) puts("false");
            else puts("maybe");
        } else {
            puts("maybe");
        }
    }
    return 0;
}
