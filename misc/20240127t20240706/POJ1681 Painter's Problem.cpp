#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

#define nullptr 0
#define constexpr const

#define range(x) x.begin(), x.end()

constexpr int N = 20;

bool mp[N][N];
bool res[N][N];

int solev() {
    int n; string s; cin >> n;
    for (int i = 1; i <= n; ++i) { cin >> s; for (int j = 1; j <= n; ++j) mp[i][j] = s[j - 1] == 'w'; }
    int ans = 1e9; for (int st = 0, fl = 1; st < (1 << n); ++st, fl = 1) {
        for (int i = 0; i <= n + 1; ++i) for (int j = 0; j <= n + 1; ++j) res[i][j] = 0;
        for (int i = 1; i <= n; ++i) res[1][i] = (st >> i - 1) & 1;
        for (int i = 2; i <= n; ++i) for (int j = 1; j <= n; ++j) res[i][j] = mp[i - 1][j] ^ res[i - 1][j - 1] ^ res[i - 1][j] ^ res[i - 1][j + 1] ^ res[i - 2][j];
        for (int i = 1; i <= n; ++i) if (mp[n][i] ^ res[n][i - 1] ^ res[n][i] ^ res[n][i + 1] ^ res[n - 1][i]) { fl = 0; break;}
        if (!fl) continue; int op = 0;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) op += res[i][j];
        ans = min(ans, op);
    } return ans == 1e9 ? -1 : ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T, r; while (cin >> T) while (T--)
    r = solev(), (r == -1) ? puts("inf") : printf("%d\n", r);
    return 0;
}
