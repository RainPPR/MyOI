/*
求 $1 \sim n$（$n \le 10^{14}$）中有多少个数字 $x$ 能被其各位数字之和整除。
如 $2024$ 各位数字之和是 $2+0+2+4=8$，且 $2024$ 能被 $8$ 整除。
*/

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,bmi,bmi2,lzcnt,tune=native")

#include <immintrin.h>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define gc() getchar_unlocked()
#define rr read()

inline ll read() {
    ll n = 0; int c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

constexpr int N = 16;

ll n; int a[N], cur, tot;
ll mem[N][N * 9][N * 9];

ll dfs(int pos, int left, int limit, int mod) {
    if (left < 0) return 0;
    if (!pos) return !left && !mod;
    auto &ans = mem[pos][left][mod];
    if (!limit && ~ans) return ans;
    int up = limit ? a[pos] : 9; ll res = 0;
    for (int i = 0; i <= up; ++i)
    res += dfs(pos - 1, left - i,
               limit && i == up,
               (mod * 10 + i) % cur);
    return !limit ? ans = res : res;
}

ll calc(ll n) {
    ll ans = 0; tot = 0;
    while (n) a[++tot] = n % 10, n /= 10;
    for (cur = 1; cur <= tot * 9; ++cur) {
        memset(mem, -1, sizeof mem);
        ans += dfs(tot, cur, 1, 0);
    } return ans;
}

int main() {
    printf("%lld\n", calc(rr));
    return 0;
}
