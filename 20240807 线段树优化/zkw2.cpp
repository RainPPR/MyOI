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

int m;

void build() {
    m = 1 << (__lg(n) + 1);
    for (int i = 1; i <= n; ++i) sum[m + i] = a[i];
    for (int i = m - 1; i; --i) push_up(i);
}

void modify(int x, int v) {
    x += m;
    while (x) {
        sum[x] += v;
        x >>= 1;
    }
}

ll query(int p, int q) {
    p += m - 1, q += m + 1;
    ll s = 0;
    while (p ^ q ^ 1) {
        s += (p % 2 == 0) * sum[p ^ 1];
        s += (q % 2 == 1) * sum[q ^ 1];
        p >>= 1, q >>= 1;
    }
    return s;
}

signed main() {
    n = rd(), q = rd();
    for (int i = 1; i <= n; ++i)
        a[i] = rd();
    build();
    while (q--) {
        int op = rd(), a = rd(), b = rd();
        if (op == 1) modify(a, b);
        else printf("%lld\n", query(a, b));
    }
    return 0;
}