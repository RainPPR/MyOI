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

#define chmin(a, x) a = min(a, x)
#define chmax(a, x) a = max(a, x)

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

#define w vector<int>({cnt[k], 2})

signed main() {
    int n = ri, ans = 0;
    vector<int> cnt(9);
    rep(i, n) ++cnt[ri % 9];
    vector<vector<int>> f(1 << 9, vector<int>(1 << 9));
    auto chk = [&] (int s, int t, int k) -> bool {
        rep(i, 9) if (s & (1 << i))
        gor(j, i + 1, 9) if (s & (1 << j))
        if ((i + j + k) % 9 == 0) return false;
        rep(i, 9) if (t & (1 << i))
        if ((i + i + k) % 9 == 0) return false;
        return true;
    }; auto chk1 = [&] (int s, int k) -> bool {
        if (!cnt[k]) return false;
        if (s & (1 << k)) return false;
        return true;
    }; auto chk2 = [&] (int s, int k) -> bool {
        if (cnt[k] < 2) return false;
        if (s & (1 << k)) return false;
        k = (9 - 2 * k % 9) % 9;
        if (s & (1 << k)) return false;
        return true;
    }; rep(s, 1 << 9) for (int t = s; t >= 0; t = (t - 1) & s) {
        ans = max(ans, f[s][t]); rep(k, 9) {
            if (!chk(s, t, k)) continue;
            if (chk1(s, k)) chmax(f[s | (1 << k)][t], f[s][t] + 1);
            if (chk2(s, k)) chmax(f[s | (1 << k)][t | (1 << k)], f[s][t] + w[3 * k % 9 == 0]);
        } if (!t) break;
    } printf("%d\n", ans);
    return 0;
}
