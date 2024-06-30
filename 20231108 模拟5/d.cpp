#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = (l); i < (r); ++i)
#define xin(i, a) for (auto i : a)

#define gc() getchar_unlocked()
#define endl '\n'

#define ri read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

inline ll qpow(ll a, ll b, ll p) {
    ll r = 1;
    for (; b; b >>= 1, a = a * a % p) if (b & 1) r = r * a % p;
    return r;
}

signed main() {
    srand(time(0) * clock());
    int n = ri, p = ri;
    ll inv = qpow(2, p - 2, p);
    double limit = (rand() % 2 + 6) * CLOCKS_PER_SEC / 10.0;
    function<ll(int, int, int)> dfs = [&] (int a, int b, int d) -> ll {
        if (a == 0 || a >= 2 * n || a < b) return 0;
        if (clock() > limit) return 0;
        return ((dfs(a + 1, 1, d + 1) + dfs(a - b, b + b, d + 1)) % p * inv + 1) % p;
    }; printf("%lld\n", dfs(n, 1, 0));
    return 0;
}
