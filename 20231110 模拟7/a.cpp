#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

#define rep(int, i, n) for (int i = 0; i < int(n); ++i)
#define gor(int, i, l, r) for (int i = int(l); i < int(r); ++i)

#define endl '\n'
#define gc() getchar_unlocked()

#define ri() read<int>()
#define rl() read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

signed main() {
    ll a = rl(), b = rl(), c = rl();
    a = min(a, c), b = min(b, c);
    printf("%lld\n", a + b - c + 1);
    return 0;
}
