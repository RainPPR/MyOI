#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

constexpr ll mod = 998244353;

signed main() {
    int n = rr, t = rr;
    vector<int> a(n);
    rep(i, n) a[i] = rr, t -= a[i];
    if (t < 0) printf("0\n"), exit(0);
    ll fr = t + n + a[0], ans = 1;
    gor(i, 1, n) ans = ans * fr % mod, fr = (fr + a[i] - 1) % mod;
    printf("%lld\n", ans * (t + 1) % mod);
    return 0;
}
