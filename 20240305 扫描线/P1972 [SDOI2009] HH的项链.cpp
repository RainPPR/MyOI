#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()

struct query {
    int id;
    int l, r;
    query() = default;
    query(int id, int l, int r): id(id), l(l), r(r) {}
    friend bool operator <(const query &a, const query &b) { return a.r < b.r; }
};

#define lowbit(x) ((x) & -(x))

constexpr int N = 1e6 + 10;

int n, m;

int s[N];

void add(int x, int v) {
    for (; x <= n; x += lowbit(x)) s[x] += v;
} int sum(int x) {
    int r = 0;
    for (; x; x -= lowbit(x)) r += s[x];
    return r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n; vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m; vector<query> q(m);
    for (int i = 0; i < m; ++i) cin >> q[i].l >> q[i].r, q[i].id = i;
    sort(range(q)); int now = 0;
    vector<int> pos(N), e(m);
    for (query &_ : q) {
        int l = _.l, r = _.r;
        for (int i = now + 1; i <= r; ++i) {
            if (pos[a[i]]) add(pos[a[i]], -1);
            add(i, 1), pos[a[i]] = i;
        } now = r; e[_.id] = sum(r) - sum(l - 1);
    } for (int i : e) cout << i << '\n';
    return 0;
}