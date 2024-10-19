// Little_RMQ

#include <bits/stdc++.h>
//#define int long long
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
const int N = 1e3 + 5, M = 335, inf = (1ll << 30), mod = 998244353;
inline int read() {
    char ch = getchar();
    int x = 0, w = 1;

    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;

        ch = getchar();
    }

    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();

    return w == 1 ? x : -x;
}
template<class T>T mmin(T a, T b) {
    return a < b ? a : b;
}
int n, ans = inf;
char s[N];
int cnt[N][N][3], pos[N][3], num[3];
//int dp[N][N][N][3];
int pool[M * M * M * 3 + 10];
signed main() {
    n = read();
    scanf("%s", s + 1);

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'Y')
            pos[++num[0]][0] = i;
        else if (s[i] == 'K')
            pos[++num[1]][1] = i;
        else
            pos[++num[2]][2] = i;
    }

    //no YK
    for (int k = 0; k < 3; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= num[k]; j++)
                cnt[i][j][k] = cnt[i][j - 1][k] + (pos[j][k] > i);

    int (&dp)[num[0] + 1][num[1] + 1][num[2] + 1][3] = decltype(dp)(pool);

    for (int i = 0; i <= num[0]; i++)
        for (int j = 0; j <= num[1]; j++)
            for (int k = 0; k <= num[2]; k++)
                for (int l = 0; l < 3; l++)
                    dp[i][j][k][l] = inf;

    dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 0;

    for (int i = 0; i <= num[0]; i++)
        for (int j = 0; j <= num[1]; j++)
            for (int k = 0; k <= num[2]; k++)
                for (int l = 0; l < 3; l++) {
                    if (i ^ num[0])
                        dp[i + 1][j][k][0] = mmin(dp[i + 1][j][k][0], dp[i][j][k][l] + cnt[pos[i + 1][0]][j][1] + cnt[pos[i + 1][0]][k][2]);
                    if ((j ^ num[1]) && l)
                        dp[i][j + 1][k][1] = mmin(dp[i][j + 1][k][1], dp[i][j][k][l] + cnt[pos[j + 1][1]][i][0] + cnt[pos[j + 1][1]][k][2]);
                    if (k ^ num[2])
                        dp[i][j][k + 1][2] = mmin(dp[i][j][k + 1][2], dp[i][j][k][l] + cnt[pos[k + 1][2]][i][0] + cnt[pos[k + 1][2]][j][1]);
                }

    for (int i = 0; i < 3; i++)
        ans = mmin(ans, dp[num[0]][num[1]][num[2]][i]);

    printf("%lld\n", ans);
    return 0;
}
/*

*/