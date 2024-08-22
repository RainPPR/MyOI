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

using ll = long long;

constexpr int N = 3e5 + 10;

namespace solev {
    int n;
    int p0, r0;
    int x0, y0;

    struct query {
        int p;
        ll r2;
        query() = default;
        query(int p, int r): p(p), r2(1ll * r * r) {}
    };

    // -------------------------------------------------------------------------

    struct magic {
        int m, p, r;
        ll dis2;
        magic() = default;
        magic(int x, int y, int m, int p, int r): m(m), p(p), r(r), dis2(1ll * (x - x0) * (x - x0) + 1ll * (y - y0) * (y - y0)) {}
    } a[N];

    bool cmp_d(const magic &a, const magic &b) {
        return a.dis2 < b.dis2;
    }

    bool cmp_m(const magic &a, const magic &b) {
        return a.m < b.m;
    }

    int block, cnt;
    int belong[N];
    int L[N], R[N];
    ll mind[N], maxd[N];

    int beg[N];

    void init() {
        sort(a + 1, a + n + 1, cmp_d);
        block = sqrt(n);
        for (int i = 1; i <= n; ++i)
            belong[i] = (i - 1) / block + 1;
        cnt = (n - 1) / block + 1;
        for (int i = 1; i <= cnt; ++i) {
            L[i] = (i - 1) * block + 1;
            R[i] = min(L[i] + block - 1, n);
            beg[i] = L[i];
            mind[i] = a[L[i]].dis2;
            maxd[i] = a[R[i]].dis2;
            sort(a + L[i], a + R[i] + 1, cmp_m);
        }
        R[cnt] = n;
    }

    queue<query> q;

    bool del[N];

    void m_push(const query &u) {
        int p = u.p;
        ll r2 = u.r2;
        for (int j = 1; j <= cnt; ++j) {
            if (mind[j] > r2)
                break;
            if (maxd[j] <= r2) {
                for (int i = beg[j]; i <= R[j]; ++i) {
                    if (del[i]) continue;
                    if (a[i].m > p) break;
                    q.emplace(a[i].p, a[i].r);
                    beg[j] = i + 1;
                }
            }
            else {
                for (int i = beg[j]; i <= R[j]; ++i) {
                    if (del[i]) continue;
                    if (a[i].m > p) continue;
                    if (a[i].dis2 > r2) continue;
                    q.emplace(a[i].p, a[i].r);
                    del[i] = true;
                }
            }
        }
    }

    // -------------------------------------------------------------------------

    int Main() {
        cin >> x0 >> y0 >> p0 >> r0 >> n;
        for (int i = 1; i <= n; ++i) {
            int x, y, m, p, r;
            cin >> x >> y >> m >> p >> r;
            a[i] = magic(x, y, m, p, r);
        }
        init();
        q.emplace(p0, r0);
        int ans = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            m_push(u);
            ++ans;
        }
        return ans - 1;
    }
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    cout << solev::Main() << endl;
    return 0;
}