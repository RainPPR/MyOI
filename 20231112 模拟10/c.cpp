#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using i2 = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

ll solve(vector<int> a, vector<int> b) {
    int n = a.size();
    multiset<int> q; ll ans = 0;
    gor(i, 1, n + 1) {
        q.insert(a[i]);
        auto t = q.rbegin();
        /*cerr << a[i] << " " << b[i] << ": ";*/
        rep(j, b[i]) ans += *t, /*cerr << *t << " ",*/ ++t;
        /*cerr << endl;*/
    } return ans;
}

signed main() {
    freopen("operate.in", "r", stdin);
    freopen("operate.out", "w", stdout);
    int n = rr, q = rr;
    vector<int> a(n + 1), b(n + 1);
    gor(i, 1, n + 1) a[i] = rr;
    gor(i, 1, n + 1) b[i] = rr;
    while (q--) {
        int x = rr;
        int bak = a[x];
        a[x] = rr;
        printf("%lld\n", solve(a, b));
        a[x] = bak;
    } return 0;
}
