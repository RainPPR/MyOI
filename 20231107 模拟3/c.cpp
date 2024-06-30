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

constexpr ll MOD = 998244353;

ll qpow(ll a, ll b, ll p) {
    ll r = 1;
    for (; b; b >>= 1, a = a * a % p) if (b & 1) r = r * a % p;
    return r;
}

ll qA(ll x) {
    x = x + 11;
    if (x >= MOD) return x - MOD;
    return x;
}

ll qB(ll x) {
    return x * 21 % MOD;
}

ll qC(ll x) {
    return qpow(x, 31, MOD);
}

unordered_map<ll, ll> dis;

ll solve(ll A, ll B) {
    queue<ll> q;
    q.push(A);
    while (q.size()) {
        ll t = q.front(); q.pop();
        if (t == B) return dis[t];
        ll a = qA(t), b = qB(t), c = qC(t);
        if (!dis.count(a)) q.push(a), dis[a] = dis[t] + 1;
        if (!dis.count(b)) q.push(b), dis[b] = dis[t] + 1;
        if (!dis.count(c)) q.push(c), dis[c] = dis[t] + 1;
    } return -1;
}

signed main() {
    int A = rr, B = rr;
    printf("%lld\n", solve(A, B));
    return 0;
}
