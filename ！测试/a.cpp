#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC optimize("inline-small-functions,inline-functions-called-once")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,bmi,bmi2,lzcnt,tune=native")
#define fO0 __attribute__ ((__optimize__ ("-O0")))

#include <immintrin.h>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

inline bool check(const ll q) {
    ll t = sqrtl(q);
    return t * t == q;
}

inline ll qpow(ll a, ll b) {
    ll r = 1;
    #pragma GCC unroll 8
    for (; b; b >>= 1) {
        if (b & 1) r = r * a;
        a = a * a;
    } return r;
}

inline ll func(const ll n) {
    return (qpow(2, n) - 1) * (qpow(5, n) - 1);
}

signed main() {
    #pragma GCC unroll 8
    for (ll i = 1; i <= INT_MAX; ++i) {
        if ((i & 0xffffff) == 0) printf("= %lld\n", i);
        if (check(func(i))) printf("%lld\n", i);
    } return 0;
}
