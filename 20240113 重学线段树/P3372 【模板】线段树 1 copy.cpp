#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (decltype(n) i = 0; i < (n); ++i)
#define gor(i, l, r) for (decltype(r) i = (l); i < (r); ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

class seg_t {

private:

struct emm {
    int l, r;
    ll v, lz;
};

int n; vector<emm> a;

void pushup(int k) {
    a[k].v = a[k * 2].v + a[k * 2 + 1].v;
}

void run(int k, ll v) {
    a[k].lz += v;
    a[k].v += v * (a[k].r - a[k].l + 1);
}

void pushdown(int k) {
    if (!a[k].lz) return;
    run(k * 2, a[k].lz);
    run(k * 2 + 1, a[k].lz);
    a[k].lz = 0;
}

void build(vector<ll> &q, int k, int l, int r) {
    a[k].lz = 0, a[k].l = l, a[k].r = r;
    if (l == r) { a[k].v = q[l]; return; }
    int mid = l + (r - l >> 1);
    build(q, k * 2, l, mid);
    build(q, k * 2 + 1, mid + 1, r);
    pushup(k);
}

void modify(int k, const int p, const int q, const ll v) {
    auto &l = a[k].l, &r = a[k].r;
    if (l >= p && r <= q) { run(k, v); return; }
    pushdown(k);
    int mid = l + (r - l >> 1);
    if (mid >= p) modify(k * 2, p, q, v);
    if (mid + 1 <= q) modify(k * 2 + 1, p, q, v);
    pushup(k);
}

ll query(int k, const int p, const int q) {
    auto &l = a[k].l, &r = a[k].r;
    if (l >= p && r <= q) return a[k].v;
    pushdown(k);
    int mid = l + (r - l >> 1); ll res = 0;
    if (mid >= p) res += query(k * 2, p, q);
    if (mid + 1 <= q) res += query(k * 2 + 1, p, q);
    return res;
}

public:

inline seg_t(vector<ll> &q) { n = q.size(), a.resize(4 * n); build(q, 1, 1, n); }
inline void add(int l, int r, ll v) { modify(1, l, r, v); }
inline ll sum(int l, int r) { return query(1, l, r); }

};

signed main() {
    int n = rr, m = rr;
    vector<ll> a(n + 1);
    rep(i, n) a[i + 1] = rr;
    seg_t seg(a);
    while (m--) {
        int tp = rr, x = rr, y = rr;
        if (tp == 1) seg.add(x, y, rr);
        else printf("%lld\n", seg.sum(x, y));
    } return 0;
}
