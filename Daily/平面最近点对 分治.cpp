#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;

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

void merge(int l, int r) {
    if (l == r) return;
    int m = l + r >> 1; ll mx = a[m].x;
    merge(l, m), merge(m + 1, r);
    inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1, cmp_y());
    vector<emm> t;
    for (int i = l; i <= r; ++i) {
        if (abs(a[i].x - mx) >= ans) continue;
        for (auto j = t.rbegin(); j != t.rend(); ++j) {
            if (a[i].y - j->y >= ans) break;
            upd_ans(a[i], *j);
        }
        t.push_back(a[i]);
    }
}

signed main() {
    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end(), cmp_x());
    merge(0, n - 1);
    printf("%.4lf\n", ans);
    return 0;
}