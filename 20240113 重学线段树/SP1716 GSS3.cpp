#pragma GCC optimize(1,2,"inline,Ofast,fast-math")

#include <immintrin.h>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar()
#define endl '\n'

#define rr read<int>()
#define ur uread<int>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = n * 10 + c - '0';
    return f ? -n : n;
}

template<typename tp>
inline tp uread() {
    tp n = 0; int c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

constexpr int root = 1;

class seg_t {

private:

struct v_t {
    int prefix, suffix; int sum, res;
    void set(const int x) { prefix = suffix = sum = res = x; }
    friend v_t operator+ (const v_t &a, const v_t &b) {
        v_t res; res.sum = a.sum + b.sum;
        res.prefix = max(a.prefix, a.sum + b.prefix);
        res.suffix = max(b.suffix, b.sum + a.suffix);
        res.res = max(max(a.res, b.res), a.suffix + b.prefix);
        return res;
    }
};

struct emm { int l, r; v_t v; };

int n; vector<emm> a;

void push_up(int k) {
    a[k].v = a[k * 2].v + a[k * 2 + 1].v;
}

void build(vector<int> &q, int k, int l, int r) {
    a[k].l = l, a[k].r = r;
    if (l == r) { a[k].v.set(q[l]); return; }
    int mid = l + (r - l >> 1);
    build(q, k * 2, l, mid);
    build(q, k * 2 + 1, mid + 1, r);
    push_up(k);
}

void modify(int k, int x, int v) {
    auto &l = a[k].l, &r = a[k].r;
    if (l == r) { a[k].v.set(v); return; }
    int mid = l + (r - l >> 1);
    if (x <= mid) modify(k * 2, x, v);
    else modify(k * 2 + 1, x, v);
    push_up(k);
}

v_t query(int k, int p, int q) {
    auto &l = a[k].l, &r = a[k].r;
    if (l >= p && r <= q) return a[k].v;
    int mid = l + (r - l >> 1);
    if (mid < p) return query(k * 2 + 1, p, q);
    if (mid + 1 > q) return query(k * 2, p, q);
    return query(k * 2, p, q) + query(k * 2 + 1, p, q);
}

public:

seg_t(vector<int> &q) { n = q.size(); a.resize(4 * n); build(q, root, 1, n); }
int mis(int l, int r) { return query(root, l, r).res; }
void change(int x, int v) { modify(root, x, v); }

};

signed main() {
    int n = ur; vector<int> a(n + 1);
    rep(i, n) a[i + 1] = rr;
    seg_t seg(a);
    int m = rr; while (m--) {
        int op = ur, l = rr, r = rr;
        if (op == 1) printf("%d\n", seg.mis(l, r));
        else seg.change(l, r);
    } return 0;
}
