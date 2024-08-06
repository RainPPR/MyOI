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

#define AWA 2

using namespace std;

// -----------------------------------------------------------------------------

int n;

int dp[52][52][52][52];

int dfs(int a, int b, int c, int d) {
    if (dp[a][b][c][d] != -1)
        return dp[a][b][c][d];
    int ans = max(c - a + 1, d - b + 1);
    //    b     d
    // a  .-----.
    //    |     |
    //    |     |
    // c  .-----.
    for (int i = a; i < c; ++i)
        ans = min(ans, dfs(a, b, i, d) + dfs(i + 1, b, c, d));
    for (int i = b; i < d; ++i)
        ans = min(ans, dfs(a, b, c, i) + dfs(a, i + 1, c, d));
    return dp[a][b][c][d] = ans;
}

int Main() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        for (int j = 1; j <= n; ++j) {
            char c = str[j - 1];
            dp[i][j][i][j] = c == '#';
        }
    }
    return dfs(1, 1, n, n);
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