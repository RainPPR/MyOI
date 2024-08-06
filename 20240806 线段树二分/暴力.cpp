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
    map<int, int> bucket;

    void init(int n) {
        n = n;
    }

    void add(int x) {
        ++bucket[x];
    }

    void del(int x) {
        assert(bucket[x] != 0);
        --bucket[x];
        if (!bucket[x])
            bucket.erase(x);
    }

    int rnk(int l, int k) {
        auto it = bucket.lower_bound(l);
        while (k > 0) {
            assert(it != bucket.end());
            k -= it->second;
            ++it;
        }
        return prev(it)->first;
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
        if (op == 1) ds::add(l);
        else if (op == 2) ds::del(l);
        else if (op == 3) {
            int k;
            cin >> k;
            cout << ds::rnk(l, k) << endl;
        }
    }
    return 0;
}