#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct emm {
    ll x, y;
    emm() = default;
    emm(ll x, ll y): x(x), y(y) {}
    friend ll operator *(const emm &a, const emm &b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
};

struct cmp_x {
    bool operator ()(const emm &a, const emm &b) const {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    }
};

struct cmp_y {
    bool operator ()(const emm &a, const emm &b) const {
        return a.y < b.y;
    }
};

double ans = 1e10;

void upd_ans(const emm &a, const emm &b) {
    double dist = sqrt(a * b);
    if (dist < ans) ans = dist;
}

vector<emm> a;

signed main() {
    int n; cin >> n; a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end(), cmp_x());
    multiset<emm, cmp_y> s;
    for (int i = 0, l = 0; i < n; ++i) {
        while (l < i && a[i].x - a[l].x >= ans) s.erase(s.find(a[l++]));
        auto it = s.lower_bound(emm(a[i].x, a[i].y - ans));
        for (; it != s.end() && it->y - a[i].y < ans; ++it) upd_ans(a[i], *it);
        s.insert(a[i]);
    }
    printf("%.4lf\n", ans);
    return 0;
}