#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1
#define D(x) ({ void(0); })
#else
#define D(x) ({ auto t = (x); cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << t << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

// -----------------------------------------------------------------------------

constexpr int N = 1e5 + 10;

int n, mod;
int src[N];

struct node {
    int l, r;
    long long sum;
    long long add, mul;
} a[N << 2];

void push_up(int k) {
    a[k].sum = (a[k << 1].sum + a[k << 1 | 1].sum) % mod;
}

void add(int k, int v) {
    a[k].add = (a[k].add + v) % mod;
    a[k].sum = (a[k].sum + 1ll * v * (a[k].r - a[k].l + 1) % mod) % mod;
}

void mul(int k, int v) {
    a[k].add = 1ll * a[k].add * v % mod;
    a[k].mul = 1ll * a[k].mul * v % mod;
    a[k].sum = 1ll * a[k].sum * v % mod;
}

void push_down(int k) {
    if (a[k].mul != 1) mul(k << 1, a[k].mul), mul(k << 1 | 1, a[k].mul), a[k].mul = 1;
    if (a[k].add != 0) add(k << 1, a[k].add), add(k << 1 | 1, a[k].add), a[k].add = 0;
}

void build(int k, int l, int r) {
    a[k].l = l, a[k].r = r;
    a[k].sum = 0, a[k].add = 0, a[k].mul = 1;
    if (l == r) return void(a[k].sum = src[l] % mod);
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    push_up(k);
}

void mul(int k, int p, int q, int v) {
    int l = a[k].l, r = a[k].r;
    if (l >= p && r <= q) return mul(k, v);
    push_down(k);
    int mid = (l + r) >> 1;
    if (p <= mid) mul(k << 1, p, q, v);
    if (q >= mid + 1) mul(k << 1 | 1, p, q, v);
    push_up(k);
}

void add(int k, int p, int q, int v) {
    int l = a[k].l, r = a[k].r;
    if (l >= p && r <= q) return add(k, v);
    push_down(k);
    int mid = (l + r) >> 1;
    if (p <= mid) add(k << 1, p, q, v);
    if (q >= mid + 1) add(k << 1 | 1, p, q, v);
    push_up(k);
}

int sum(int k, int p, int q) {
    int l = a[k].l, r = a[k].r;
    if (l >= p && r <= q) return a[k].sum;
    push_down(k);
    int mid = (l + r) >> 1;
    if (q <= mid) return sum(k << 1, p, q);
    if (p >= mid + 1) return sum(k << 1 | 1, p, q);
    return (sum(k << 1, p, q) + sum(k << 1 | 1, p, q)) % mod;
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    cin >> n >> mod;
    for (int i = 1; i <= n; ++i)
        cin >> src[i];
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int op, l, r, v;
        cin >> op >> l >> r;
        if (op <= 2) cin >> v;
        if (op == 1) mul(1, l, r, v);
        else if (op == 2) add(1, l, r, v);
        else cout << sum(1, l, r) << endl;
    }
    return 0;
}