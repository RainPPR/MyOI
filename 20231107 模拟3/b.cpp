#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define gcd(a, b) __gcd(a, b)

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

using ll = long long;

const ll MOD = 1e9 + 7;

vector<int> a;
int n, k;

const int N = 1010;

ll dfs(int len, int now, int g) {
    if (now == n) return 1ll * g * len == k;
    ll res = (dfs(len, now + 1, g) + dfs(len + 1, now + 1, gcd(g, a[now]))) % MOD;
    return res;
} ll solve() {
    ll res = 0;
    rep(i, n) res = (res + dfs(1, i + 1, a[i])) % MOD;
    return res;
}

signed main() {
    n = rr, k = rr;
    a.resize(n);
    rep(i, n) a[i] = rr;
    printf("%lld\n", solve());
    return 0;
}
