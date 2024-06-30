#pragma GCC optimize(1,2,"inline","Ofast,fast-math")

#include <immintrin.h>
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define endl '\n'
#define gc() getchar_unlocked()

#define ur uread<unsigned>()

template<typename tp>
inline tp uread() {
    tp n = 0; int c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

vector<int> input(int &n) {
    n = ur; vector<int> socks;
    int k = ur, now = 1;
    rep(i, k) {
        int a = ur;
        #pragma GCC unroll 8
        gor(j, now, a) socks.push_back(j), socks.push_back(j);
        socks.push_back(a); now = a + 1;
    }
    #pragma GCC unroll 8
    gor(j, now, n + 1) socks.push_back(j), socks.push_back(j);
    n = socks.size(); return socks;
}

#define abs(x) ((x) < 0 ? -(x) : (x))

signed main() {
    int n; auto a = input(n); vector<int> ldif(n), rdif(n);
    ldif[1] = abs(a[1] - a[0]);
    #pragma GCC unroll 8
    for (int i = 3; i < n; i += 2) ldif[i] = ldif[i - 2] + abs(a[i] - a[i - 1]);
    if ((n & 1) ^ 1) printf("%d\n", ldif[n - 1]), exit(0);
    rdif[n - 2] = abs(a[n - 2] - a[n - 1]);
    #pragma GCC unroll 8
    for (int i = n - 4; i >= 0; i -= 2) rdif[i] = rdif[i + 2] + abs(a[i] - a[i + 1]);
    int ans = 1e9;
    #pragma GCC unroll 8
    for (int i = 2; i < n; i += 2) ans = min(ans, ldif[i - 1] + rdif[i + 1]);
    printf("%d\n", ans);
    return 0;
}
