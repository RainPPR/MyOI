#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

using ll = long long;

constexpr ll mod = 998244353;

pair<ll, ll> exgcd(ll a, ll b) {
    if (b == 0) return {1, 0};
    auto t = exgcd(b, a % b);
    return {t.second, t.first - a / b * t.second};
}

ll qpow(ll a, ll b, ll m) {
    ll r = 1; for (; b; b >>= 1) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
    } return r;
}

ll inv(ll a, ll m) {
    auto x = exgcd(a, m).first;
    return (x % m + m) % m;
}

const ll inv21 = qpow(21, mod - 2, mod);
const ll inv31 = inv(31, mod - 1);

unordered_map<ll, ll> ldis, rdis;

ll solve(ll A, ll B) {
    if (A == B) return 0;
    queue<ll> a, b;
    a.push(A), b.push(B);
    ldis[A] = 0, rdis[B] = 0;
    ll now; while (1) {
        #define as (now - 11 + mod) % mod
        #define bs now * inv21 % mod
        #define cs qpow(now, inv31, mod)
        now = b.front(); b.pop();
        if (!rdis.count(as)) b.push(as), rdis[as] = rdis[now] + 1;
        if (!rdis.count(bs)) b.push(bs), rdis[bs] = rdis[now] + 1;
        if (!rdis.count(cs)) b.push(cs), rdis[cs] = rdis[now] + 1;
        #define as (now + 11) % mod
        #define bs (now * 21) % mod
        #define cs qpow(now, 31, mod)
        now = a.front(); a.pop();
        if (rdis.count(now)) return ldis[now] + rdis[now];
        if (!ldis.count(as)) a.push(as), ldis[as] = ldis[now] + 1;
        if (!ldis.count(bs)) a.push(bs), ldis[bs] = ldis[now] + 1;
        if (!ldis.count(cs)) a.push(cs), ldis[cs] = ldis[now] + 1;
    } return -1;
}

signed main() {
    int A = rr, B = rr;
    printf("%lld\n", solve(A, B));
    return 0;
}
