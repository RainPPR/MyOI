#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

#define endl '\n'
#define gc() getchar_unlocked()

#define ri read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

ll mem[40][40][2];

ll have(ll n, ll x) {
    if (x > n) return 0;
    ll _n = n, _x = x;
    int len = 0, tar = 0;
    while (_n) ++len, _n >>= 1;
    while (_x) ++tar, _x >>= 1;
    memset(mem, -1, sizeof mem);
    function<ll(int, int, int)> dp = [&](int pos, int cnt, int limit) {
        if (cnt > tar) return 0LL;
        if (!pos) return 1LL;
        auto &res = mem[pos][cnt][limit];
        if (res != -1) return res;
        int up = limit ? ((n >> pos - 1) & 1) : 1;
        res = 0LL;
        if ((x >> pos - 1) & 1) {
            if (up != 0) res = dp(pos - 1, cnt + 1, limit);
        } else { for (int i = 0; i <= up; ++i)
            res += dp(pos - 1, cnt, limit & (i == up));
        } return res;
    }; return dp(len, 0, 1);
}

bool check(pll rg, ll x) {
    ll cnt = have(rg.second, x);
    if (rg.first > 0)
        cnt -= have(rg.first - 1, x);
    return cnt > 0;
}

signed main() {
    int n = ri; vector<pll> a(n);
    auto input = [&] { ll x = rl, y = rl; return make_pair(x, y); };
    generate(a.begin(), a.end(), input);
    // cout << "FINISH INPUT " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    ll now = 0;
    for (int i = 33; ~i; --i) {
        // cout << "FINISH  " << i << " " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
        ll t = now | (1ll << i); bool can = true;
        for (pll j : a) if (!check(j, t)) { can = false; break; }
        if (can) now = t;
    } cout << now << endl;
    return 0;
}
