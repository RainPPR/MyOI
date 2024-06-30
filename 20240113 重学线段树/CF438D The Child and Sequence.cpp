#pragma GCC optimize(1,2,"inline,Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,bmi,bmi2,lzcnt,tune=native")

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

struct emm {
    int l, r;
    ll v, mx;
};

int n; vector<emm> a;

void push_up(int k) {
    a[k].v = a[k * 2].v + a[k * 2 + 1].v;
    a[k].mx = max(a[k * 2].mx, a[k * 2 + 1].mx);
}

void build(vector<ll> &q, int k, int l, int r) {
    a[k].l = l, a[k].r = r;
    if (l == r) { a[k].v = a[k].mx = q[l]; return; }
    int mid = l + (r - l >> 1);
    build(q, k * 2, l, mid);
    build(q, k * 2 + 1, mid + 1, r);
    push_up(k);
}

ll query(int k, int p, int q) {
    auto &l = a[k].l, &r = a[k].r;
    if (l >= p && r <= q) return a[k].v;
    int mid = l + (r - l >> 1); ll res = 0;
    if (mid >= p) res += query(k * 2, p, q);
    if (mid + 1 <= q) res += query(k * 2 + 1, p, q);
    return res;
}

void modify(int k, int x, ll v) {
    auto &l = a[k].l, &r = a[k].r;
    if (l == r) { a[k].v = a[k].mx = v; return; }
    int mid = l + (r - l >> 1);
    if (x <= mid) modify(k * 2, x, v);
    else modify(k * 2 + 1, x, v);
    push_up(k);
}

void putmod(int k, int p, int q, ll m) {
    auto &l = a[k].l, &r = a[k].r;
    if (l == r) { a[k].v = a[k].mx = a[k].v % m; return; }
    int mid = l + (r - l >> 1);
    if (mid >= p && a[k * 2].mx >= m) putmod(k * 2, p, q, m);
    if (mid + 1 <= q && a[k * 2 + 1].mx >= m) putmod(k * 2 + 1, p, q, m);
    push_up(k);
}

public:

seg_t(vector<ll> &q) { n = q.size(); a.resize(n * 4); build(q, root, 1, n); }
ll sum(int l, int r) { return query(root, l, r); }
void mod(int l, int r, ll x) { putmod(root, l, r, x); }
void change(int k, ll x) { modify(root, k, x); }

};

signed main() {
    int n = ur, m = ur;
    vector<ll> a(n + 1);
    rep(i, n) a[i + 1] = ur;
    seg_t seg(a);
    while (m--) {
        int op = ur, x = ur, y = ur;
        if (op == 1) printf("%lld\n", seg.sum(x, y));
        else if (op == 3) seg.change(x, y);
        else seg.mod(x, y, ur);
    } return 0;
}
