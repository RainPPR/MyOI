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

    int block, cnt;
    int belong[N];
    int L[N], R[N];
    int bucket[N], sum[N];

    void init(int n) {
        block = sqrt(n);
        for (int i = 1; i <= n; ++i)
            belong[i] = (i - 1) / block + 1;
        cnt = (n - 1) / block + 1;
        for (int i = 1; i <= cnt; ++i)
            R[i] = i * block, L[i] = R[i] - block + 1;
        R[cnt] = n;
    }

    void add(int x) {
        ++bucket[x];
        ++sum[belong[x]];
    }

    void del(int x) {
        --bucket[x];
        --sum[belong[x]];
    }

    int rnk(int l, int k) {
        int p = belong[l];
        for (int i = l; i <= R[p]; ++i) {
            k -= bucket[i];
            if (k <= 0) return i;
        }
        int pos = p + 1;
        while (sum[pos] < k) {
            if (pos > cnt) {
                exit(1);
            }
            k -= sum[pos], ++pos;
        }
        for (int i = L[pos]; i <= R[pos]; ++i) {
            k -= bucket[i];
            if (k <= 0) return i;
        }
        exit(1);
        return -1;
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