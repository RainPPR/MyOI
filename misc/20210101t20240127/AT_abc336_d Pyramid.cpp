#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,bmi,bmi2,lzcnt,tune=native")

#include <immintrin.h>
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)
#define rgor(i, r, l) for (decltype(l) i = r - 1; i >= l; --i)

#define gc() getchar_unlocked()
#define rr read()

inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) n = n * 10 + c - '0';
    return f ? -n : n;
}

signed main() {
    int n = rr, ans = 1; vector<int> a(n), la(n), ra(n);
    la[0] = ra[n - 1] = 1; for (int &i : a) i = rr;
    gor(i, 1, n) la[i] = min(a[i], la[i - 1] + 1);
    rgor(i, n, 0) ra[i] = min(a[i], ra[i + 1] + 1);
    rep(i, n) ans = max(ans, min(la[i], ra[i]));
    printf("%d\n", ans); return 0;
}
