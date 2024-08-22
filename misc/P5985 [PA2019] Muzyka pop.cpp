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

#define AWA 2

using ll = long long;

constexpr int N = 210;

ll n, m, a[N], s[N];

ll dp[64][N][N][2];

ll Main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    memset(dp, -0x3f, sizeof dp);
    for (int i = 1; i <= n; ++i)
        dp[0][i][i][0] = dp[0][i][i][1] = 0;
    for (int i = 0; i < 64; ++i)
        for (int j = 1; j <= n + 1; ++j)
            for (int k = 0; k < 2; ++k)
                dp[i][j][j - 1][k] = 0;
    for (int i = 1; i < 64; ++i)
        for (int l = 1; l <= n; ++l)
            for (int r = l; r <= n; ++r)
                for (int j = 0; j < 2; ++j)
                    if (!j || (m & (1ll << (i - 1))))
                        for (int k = l - 1; k <= r; ++k)
                            dp[i][l][r][j] = max(dp[i][l][r][j], dp[i - 1][l][k][0] + dp[i - 1][k + 1][r][j] + s[r] - s[k]);
                    else
                        dp[i][l][r][j] = dp[i - 1][l][r][j];
    return dp[63][1][n][1];
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    #if AWA == 0

    #elif AWA == 1
    Main();

    #elif AWA == 2
    cout << Main() << endl;

    #elif AWA == 3
    int T; cin >> T;
    while (T--) Main();

    #elif AWA == 4
    int T; cin >> T;
    while (T--) cout << Main() << endl;

    #elif AWA == 5
    int T; cin >> T;
    while (T--) cout << Main() << " ";
    cout << endl;

    #else
    __builtin_unreachable();
    #endif
    return 0;
}