#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int N = 2e5 + 10;

int n, m;

struct node {
    int l, a;
    node() = default;
    node(int l, int a): l(l), a(a) {}
};

vector<node> q[N];

class segment {

struct emm {
    int l, r;
    ll s, tag;
};

vector<emm> a;

void build(int k, int l, int r) {
    a[k].l = l, a[k].r = r;
    if (l == r) return void(a[k].s = a[k].tag = 0);
    int mid = l + r >> 1;
    build(k * 2, l, mid), build(k * 2 + 1, mid + 1, r);
}

void push_up(int k) {
    a[k].s = max(a[k * 2].s, a[k * 2 + 1].s);
}

void action(int k, ll v) {
    a[k].tag += v;
    a[k].s += v;
}

void push_down(int k) {
    if (a[k].tag == 0) return;
    action(k * 2, a[k].tag);
    action(k * 2 + 1, a[k].tag);
    a[k].tag = 0;
}

void modify(int k, int p, int q, ll v) {
    int l = a[k].l, r = a[k].r;
    if (r < p || l > q) return;
    if (l >= p && r <= q) return void(action(k, v));
    push_down(k);
    modify(k * 2, p, q, v), modify(k * 2 + 1, p, q, v);
    push_up(k);
}

ll query(int k, int p, int q) {
    int l = a[k].l, r = a[k].r;
    if (r < p || l > q) return -1e9;
    if (l >= p && r <= q) return a[k].s;
    push_down(k);
    return max(query(k * 2, p, q), query(k * 2 + 1, p, q));
}

public:

segment(int n) { a.resize(n << 3); build(1, 1, n); }
void add(int l, int r, ll x) { modify(1, l, r, x); }
ll maxx(int l, int r) { return query(1, l, r); }

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int l, r, a; cin >> l >> r >> a;
        q[r].push_back(node(l, a));
    }
    segment seg(n);
    for (int r = 1; r <= n; ++r) {
        ll opt = seg.maxx(1, r);
        seg.add(r, r, max(opt, 0ll));
        for (node p : q[r]) seg.add(p.l, r, p.a);
    }
    cout << max(seg.maxx(1, n), 0ll) << endl;
    return 0;
}
