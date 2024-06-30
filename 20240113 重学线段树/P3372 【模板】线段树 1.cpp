#include <bits/stdc++.h>

using namespace std;

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

using tpp = long long;

class seg_t {

#define xbl k * 2, l, mid
#define xbr k * 2 + 1, mid + 1, r
#define getmid() int mid = l + (r - l >> 1)

private:

int n; vector<tpp> a, lz;

void pushup(int k) {
    a[k] = a[k * 2] + a[k * 2 + 1];
}

void run(int k, int l, int r, tpp v) {
    a[k] += v * (r - l + 1), lz[k] += v;
}

void pushdown(int k, int l, int r) {
    if (!lz[k]) return;
    getmid();
    run(xbl, lz[k]);
    run(xbr, lz[k]);
    lz[k] = 0;
}

void build(vector<tpp> &q, int k, int l, int r) {
    if (l == r) { a[k] = q[l]; return; }
    getmid();
    build(q, xbl);
    build(q, xbr);
    pushup(k);
}

void modify(int k, int l, int r, const int p, const int q, const tpp v) {
    if (r < p || l > q) return;
    if (l >= p && r <= q) { run(k, l, r, v); return; }
    pushdown(k, l, r); getmid();
    modify(xbl, p, q, v);
    modify(xbr, p, q, v);
    pushup(k);
}

tpp query(int k, int l, int r, const int p, const int q) {
    if (r < p || l > q) return 0;
    if (l >= p && r <= q) return a[k];
    pushdown(k, l, r); getmid();
    return query(xbl, p, q) + query(xbr, p, q);
}

public:

seg_t(int s) { n = s, a.resize(4 * n), lz.resize(4 * n); }
seg_t(vector<tpp> &q) { n = q.size(), a.resize(4 * n), lz.resize(4 * n); build(q, 1, 1, n); }
void add(int l, int r, tpp v) { modify(1, 1, n, l, r, v); }
tpp sum(int l, int r) { return query(1, 1, n, l, r); }

};

signed main() {
    int n = rr, m = rr;
    vector<tpp> a(n + 1);
    rep(i, n) a[i + 1] = rr;
    seg_t seg(a);
    while (m--) {
        int tp = rr, x = rr, y = rr;
        if (tp == 1) seg.add(x, y, rr);
        else printf("%lld\n", seg.sum(x, y));
        // cerr << "EDB: ";
        // for (int i = 1; i <= n; ++i) cerr << seg.sum(i, i) << " ";
        // cerr << endl;
    } return 0;
}
