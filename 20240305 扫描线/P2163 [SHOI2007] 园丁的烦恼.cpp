#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

#define range(x) x.begin(), x.end()

struct point {
    int x, y;
    point() = default;
    point(int x, int y): x(x), y(y) {}
    friend bool operator <(const point &a, const point &b) { return a.x < b.x; }
};

struct query {
    int x, y, v, id;
    query() = default;
    query(int x, int y, int v, int id): x(x), y(y), v(v), id(id) {}
    friend bool operator <(const point &a, const point &b) { return a.x < b.x; }
};

constexpr int N = 1e7 + 10;

int s[N];

#define lowbit(x) ((x) & -(x))

void add(int x, int v) {
    for (; x < N; x += lowbit(x)) s[x] += v;
}

int sum(int x) {
    int r = 0;
    for (; x; x -= lowbit(x)) r += s[x];
    return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m; vector<point> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y, ++a[i].x, ++a[i].y;
    sort(range(a)); vector<query> q(m << 2);
    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ++x1, ++y1, ++x2, ++y2;
        q[i] = query(x2, y2, 1, i);
        q[i + m] = query(x1 - 1, y2, -1, i);
        q[i + 2 * m] = query(x2, y1 - 1, -1, i);
        q[i + 3 * 2] = query(x1 - 1, y1 - 1, 1, i);
    } sort(range(q)); vector<int> ans(m);
    int cur = 0; for (int i = m; i < (m << 2); ++i) {
        int x = q[i].x, y = q[i].y, v = q[i].v;
        for (; cur < n && a[cur].x <= x; ++cur) add(a[cur].y, 1);
        ans[q[i].id] += v * sum(y);
    } for (int i : ans) cout << i << endl;
    return 0;
}
