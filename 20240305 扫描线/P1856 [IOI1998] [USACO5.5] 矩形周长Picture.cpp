#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()

using ll = long long;

struct line {
    int y, x1, x2, v;
    line() = default;
    line(int y, int x1, int x2, int v): y(y), x1(x1), x2(x2), v(v) {}
    friend bool operator <(const line &a, const line &b) { return a.y < b.y; }
};

class segment {

private:

struct emm {
    int l, r;
    int cov, len;
};

vector<emm> a;

void push_up(int k) {
    if (a[k].cov) a[k].len = a[k].r - a[k].l;
    else a[k].len = a[k * 2].len + a[k * 2 + 1].len;
}

void build(vector<int> &p, int k, int l, int r) {
    a[k].l = p[l], a[k].r = p[r];
    a[k].cov = a[k].len = 0;
    if (r - l == 1) return;
    int mid = r + l >> 1;
    build(p, k * 2, l, mid);
    build(p, k * 2 + 1, mid, r);
}

void modify(int k, int p, int q, int v) {
    int l = a[k].l, r = a[k].r;
    if (l >= p && r <= q) return void((a[k].cov += v, push_up(k)));
    if (a[k * 2].r > p) modify(k * 2, p, q, v);
    if (a[k * 2 + 1].l < q) modify(k * 2 + 1, p, q, v);
    push_up(k);
}

public:

segment(vector<int> &p, int n) { a.resize(n << 3); build(p, 1, 1, n); }
int xht() { return a[1].len; }
void change(int l, int r, int v) { modify(1, l, r, v); }

};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    int n, lt; cin >> n;
    vector<line> a1(n * 2), a2(n * 2);
    vector<int> p1(n * 2); vector<int> p2(n * 2);
    p1.push_back(-1e5); p2.push_back(-1e5);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        p1[i] = x1, p1[i + n] = x2;
        p2[i] = y1, p2[i + n] = y2;
        a1[i] = line(y1, x1, x2, 1);
        a1[i + n] = line(y2, x1, x2, -1);
        a2[i] = line(x1, y1, y2, 1);
        a2[i + n] = line(x2, y1, y2, -1);
    }
    sort(range(a1)), sort(range(p1));
    sort(range(a2)), sort(range(p2));
    int tot1 = unique(range(p1)) - p1.begin();
    int tot2 = unique(range(p2)) - p2.begin();
    segment seg1(p1, tot1 - 1);
    segment seg2(p2, tot2 - 1);
    ll res = 0; int lt1 = 0, lt2 = 0;
    for (int i = 0; i < 2 * n; ++i) {
        seg1.change(a1[i].x1, a1[i].x2, a1[i].v);
        seg2.change(a2[i].x1, a2[i].x2, a2[i].v);
        int rt1 = seg1.xht(); res += abs(rt1 - lt1);
        int rt2 = seg2.xht(); res += abs(rt2 - lt2);
        lt1 = rt1, lt2 = rt2;
    } cout << res << endl;
    return 0;
}
