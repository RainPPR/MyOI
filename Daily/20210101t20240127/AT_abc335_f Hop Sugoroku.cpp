#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define gc() getchar_unlocked()
#define rr read()

inline int read() {
    int n = 0, c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

constexpr ll mod = 998244353ll;

inline void add(ll &a, const ll b) { a += b; if (a >= mod) a -= mod; }
inline ll sum(const ll a, const ll b) { ll r = a + b; return r >= mod ? r - mod : r; }

int main() {
    int n = rr; vector<int> A(n); for (int &i : A) i = rr;
    vector<ll> dp(n), mem(n); dp[0] = 1; ll res = 0;
    for (int i = 0; i < n; ++i) {
        add(res, dp[i]); ll b = sum(dp[i], mem[i]);
        for (int j = i + A[i]; j < n; j += A[i])
        if ((add(dp[j], b), A[j]) == A[i]) { add(mem[j], b); break; }
    } printf("%lld\n", res);
    return 0;
}
