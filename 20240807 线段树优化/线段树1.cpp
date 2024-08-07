#define NDEBUG 1

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct io_t {
    #define MAXSIZE (1 << 20)
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;

    io_t() : p1(buf), p2(buf), pp(pbuf) {}
    ~io_t() { fwrite(pbuf, 1, pp - pbuf, stdout); }

    char gc() {
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }

    template <typename T>
    T read() {
        T n = 0;
        bool f = 0;
        int c = gc();
        for ( ; !isdigit(c); c = gc())
            f |= c == '-';
        for ( ; isdigit(c); c = gc())
            n = n * 10 + c - '0';
        return f ? -n : n;
    }
} io;

#define rd() io.read<int>()

constexpr int N = 1e6 + 10;

int n, q, a[N];

ll sum[N << 2];

void push_up(int k) {
    sum[k] = sum[k << 1] + sum[k << 1 | 1];
}

void build(int k, int l, int r) {
    sum[k] = 0;
    if (l == r) {
        sum[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    push_up(k);
}

void modify(int k, int l, int r, int x, int v) {
    if (l == r) {
        sum[k] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(k << 1, l, mid, x, v);
    else modify(k << 1 | 1, mid + 1, r, x, v);
    push_up(k);
}

ll query(int k, int l, int r, int p, int q) {
    if (l >= p && r <= q) return sum[k];
    int mid = (l + r) >> 1;
    ll res = 0;
    if (p <= mid) res += query(k << 1, l, mid, p, q);
    if (q >= mid + 1) res += query(k << 1 | 1, mid + 1, r, p, q);
    return res;
}

signed main() {
    n = rd(), q = rd();
    for (int i = 1; i <= n; ++i)
        a[i] = rd();
    build(1, 1, n);
    while (q--) {
        int op = rd(), a = rd(), b = rd();
        if (op == 1) modify(1, 1, n, a, b);
        else printf("%lld\n", query(1, 1, n, a, b));
    }
    return 0;
}