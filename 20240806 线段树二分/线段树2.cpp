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

namespace ds {
    constexpr int N = 5e5 + 10;

    int n;

    struct node {
        int l, r, v;
    } a[N << 2];

    void build(int k, int l, int r) {
        a[k] = {l, r, 0};
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(k << 1, l, mid);
        build(k << 1 | 1, mid + 1, r);
    }

    void modify(int x, int v) {
        int root = 1;
        while (true) {
            a[root].v += v;
            int l = a[root].l, r = a[root].r;
            if (l == r) break;
            int mid = (l + r) >> 1;
            if (x <= mid) root = root << 1;
            else root = root << 1 | 1;
        }
    }

    int query(int k, int p, int q) {
        int l = a[k].l, r = a[k].r;
        if (l >= p && r <= q) return a[k].v;
        int mid = (l + r) >> 1;
        if (q <= mid) return query(k << 1, p, q);
        if (p >= mid + 1) return query(k << 1 | 1, p, q);
        return query(k << 1, p, q) + query(k << 1 | 1, p, q);
    }

    void init(int m) {
        build(1, 1, n = m);
    }

    void add(int x) {
        modify(x, 1);
    }

    void del(int x) {
        modify(x, -1);
    }

    int rnk(int p, int k) {
        int l = p, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (query(1, p, mid) >= k)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    int n, q;
    cin >> n >> q;
    ds::init(n);
    while (q--) {
        int op, l;
        cin >> op >> l;
        if (op == 1) ds::add(l),
            assert(l <= n);
        else if (op == 2) ds::del(l),
            assert(l <= n);
        else if (op == 3) {
            int k;
            cin >> k;
            cout << ds::rnk(l, k) << endl;
        }
    }
    return 0;
}