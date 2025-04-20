#pragma GCC optimize("Ofast,fast-math,-ffast-math")
#pragma GCC optimize("no-stack-protector,-funsafe-loop-optimizations")
#pragma GCC optimize("-fthread-jumps,unroll-loops,-funroll-loops")
#pragma GCC optimize("-falign-jumps,-falign-loops,-falign-labels,-falign-functions")
#pragma GCC optimize("-fexpensive-optimizations,-fdelete-null-pointer-checks")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define chmin(a, x) ((a) = min(a, x))
#define chmax(a, x) ((a) = max(a, x))

#define fi first
#define se second

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define end '\n'

#define open(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)

#define printi(q) printf("%d\n", int(q))
#define printl(q) printf("%lld\n", ll(q))

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

signed main() {
    open("backpack");
    int n = rr, m = rr;
    vector<vector<pii>> a(m + 1);
    rep(i, n) { int l = rr, r = rr, v = rr; a[r].push_back({l, v}); }
    vector<ll> f(m + 1), g(m + 1);
    gor(i, 1, m + 1) {
        for (pii j : a[i]) chmax(f[i], g[j.fi - 1] + j.se);
        g[i] = max(g[i - 1], f[i]);
    } printl(g[m]);
    return 0;
}
