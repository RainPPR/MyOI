#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

constexpr int N = 5e5 + 10;

int n, m, a[N];

// ----------------------------------------------------------------------------

#define ls(k) ((k) << 1)
#define rs(k) ((k) << 1 | 1)

struct imp {
    int sum, ans;
    int pre, suf;
    imp() = default;
    imp(int x): sum(x), ans(x), pre(x), suf(x) {}
    imp(int s, int a, int p, int f): sum(s), ans(a), pre(p), suf(f) {}
    friend imp operator +(const imp &a, const imp &b) {
        imp r;
        r.sum = a.sum + b.sum;
        r.pre = max(a.pre, a.sum + b.pre);
        r.suf = max(b.suf, b.sum + a.suf);
        r.ans = max({a.ans, b.ans, a.suf + b.pre});
        return r;
    }
};

struct node : imp {
    int l, r; imp ot;
} seg[N << 2];

void push_up(int k) {
    seg[k].ot = seg[ls(k)].ot + seg[rs(k)].ot;
}

void action(int k, int v) {
    seg[k].ot = imp(v);
}

void build(int k, int l, int r) {
    seg[k].l = l, seg[k].r = r;
    if (l == r) return action(k, a[l]);
    int mid = l + r >> 1;
    build(ls(k), l, mid), build(rs(k), mid + 1, r);
    push_up(k);
}

void modify(int k, int x, int v) {
    int l = seg[k].l, r = seg[k].r;
    if (l == r) return action(k, v);
    int mid = l + r >> 1;
    // [l, mid] [mid + 1, r]
    if (x <= mid) modify(ls(k), x, v);
    else modify(rs(k), x, v);
    push_up(k);
}

imp query(int k, int p, int q) {
    int l = seg[k].l, r = seg[k].r;
    if (l >= p && r <= q) return seg[k].ot;
    int mid = l + r >> 1;
    // [l, mid] [mid + 1, r]
    if (q <= mid) return query(ls(k), p, q);
    if (p >= mid + 1) return query(rs(k), p, q);
    return query(ls(k), p, q) + query(rs(k), p, q);
}

// ----------------------------------------------------------------------------

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    copy_n(istream_iterator<int>(cin), n, a + 1);
    build(1, 1, n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 2) modify(1, l, r);
        else {
            if (l > r) swap(l, r);
            cout << query(1, l, r).ans << endl;
        }
    }
    return 0;
}