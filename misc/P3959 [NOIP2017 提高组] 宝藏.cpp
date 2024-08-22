#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1
#define D(x) ({ void(0); })
#else
#define D(x) ({ cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << (x) << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

// -----------------------------------------------------------------------------

constexpr int INF = 0x3f3f3f3f;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

#define bin(x, k) ({ bitset<k>(x).to_string(); })

int n, m;

int g[12][12];

int to[12];

int mt[1 << 12];

int dp[1 << 12][12];

int dis[1 << 12][1 << 12];

int getdis(int a, int b) {
    // a : up, b : down
    if (dis[a][b])
        return dis[a][b];
    int ans = 0;
    int mask = b;
    while (mask) {
        int u = __builtin_ctz(mask);
        int res = INF;
        int mask2 = a;
        while (mask2) {
            int v = __builtin_ctz(mask2);
            res = min(res, g[u][v]);
            mask2 &= mask2 - 1;
        }
        if (res == INF) {
            ans = INF;
            break;
        }
        ans += res;
        mask &= mask - 1;
    }
    return dis[a][b] = ans;
    // calc dis[a][b]
}

int dfs(int S, int d) {
    if (dp[S][d] != -1)
        return dp[S][d];
    if (d == 0)
        return INF;
    int ans = INF;
    for (int mask = mt[S]; mask; mask = (mask - 1) & mt[S]) {
        int pay = getdis(mask, S ^ mask);
        if (pay == 0) continue;
        if (pay != INF) ans = min(ans, dfs(mask, d - 1) + pay * d);
    }
    return dp[S][d] = ans;
}

void Main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
        to[u] |= 1 << v, to[v] |= 1 << u;
    }
    for (int S = 0; S < (1 << n); ++S) {
        int mask = S;
        while (mask) {
            mt[S] |= to[__builtin_ctz(mask)];
            mask &= mask - 1;
        }
        mt[S] &= S;
    }
    int ans = INF;
    for (int start = 0; start < n; ++start) {
        memset(dp, -1, sizeof dp);
        dp[1 << start][0] = 0;
        for (int d = 0; d < n; ++d)
            ans = min(ans, dfs((1 << n) - 1, d));
    }
    cout << ans << endl;
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    Main();
    return 0;
}