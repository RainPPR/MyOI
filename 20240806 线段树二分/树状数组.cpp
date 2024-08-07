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

    int n, s[N];

    #define lowbit(x) ((x) & -(x))

    void modify(int x, int v) {
        for (; x <= n; x += lowbit(x))
            s[x] += v;
    }

    int query(int x) {
        int r = 0;
        for (; x; x -= lowbit(x))
            r += s[x];
        return r;
    }

    int query(int p, int q) {
        return query(q) - query(p - 1);
    }

    void init(int m) {
        n = m;
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
            if (query(p, mid) >= k)
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