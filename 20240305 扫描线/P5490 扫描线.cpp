#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define range(x) x.begin(), x.end()

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
    int cnt, len;
};

vector<emm> a;

void push_up(int k) {
    if (a[k].cnt) a[k].len = a[k].r - a[k].l;
    else a[k].len = a[k * 2].len + a[k * 2 + 1].len;
}

void build(vector<int> &p, int k, int l, int r) {
    a[k].l = p[l], a[k].r = p[r];
    a[k].len = a[k].cnt = 0;
    if (r - l == 1) return;
    int mid = l + r >> 1;
    build(p, k * 2, l, mid);
    build(p, k * 2 + 1, mid, r);
}

void modify(int k, int p, int q, int v) {
    int l = a[k].l, r = a[k].r;
    if (l >= p && r <= q) return void((a[k].cnt += v, push_up(k)));
    if (a[k * 2].r > p) modify(k * 2, p, q, v);
    if (a[k * 2 + 1].l < q) modify(k * 2 + 1, p, q, v);
    push_up(k);
}

public:

segment(vector<int> &p, int n) { a.resize(n << 3); build(p, 1, 1, n); }
void change(int l, int r, int v) { modify(1, l, r, v); }
int xht() { return a[1].len; }

};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<line> a(n * 2);
    vector<int> p(n * 2);
    p.push_back(-1);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p[i] = x1, p[i + n] = x2;
        a[i] = line(y1, x1, x2, 1);
        a[i + n] = line(y2, x1, x2, -1);
    }
    sort(range(a)), sort(range(p));
    int tot = unique(range(p)) - p.begin();
    segment seg(p, tot - 1); ll ans = 0;
    for (int i = 0; i < 2 * n - 1; ++i) {
        seg.change(a[i].x1, a[i].x2, a[i].v);
        ans += 1ll * seg.xht() * (a[i + 1].y - a[i].y);
    } cout << ans << endl;
    return 0;
}
