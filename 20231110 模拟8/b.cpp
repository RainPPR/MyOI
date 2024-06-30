#ifndef MY_TEST
#pragma GCC optimize("Ofast,fast-math,-ffast-math")
#pragma GCC optimize("no-stack-protector,-funsafe-loop-optimizations")
#pragma GCC optimize("-fthread-jumps,unroll-loops,-funroll-loops")
#pragma GCC optimize("-falign-jumps,-falign-loops,-falign-labels,-falign-functions")
#pragma GCC optimize("-fexpensive-optimizations,-fdelete-null-pointer-checks")
#endif

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define chmin(a, x) ((a) = min(a, x))
#define chmax(a, x) ((a) = max(a, x))

constexpr int N = 1003;
constexpr int INF = 1e9;

int sum[N][3], sub[N][3];
int pool[N * N * N >> 2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; string s; cin >> n >> s;
    int ycnt = 0, kcnt = 0, ocnt = 0;

    gor(i, 1, n + 1) {
        sum[i][0] = sum[i - 1][0];
        sum[i][1] = sum[i - 1][1];
        sum[i][2] = sum[i - 1][2];
        if (s[i - 1] == 'Y') ++sum[i][0], sub[++ycnt][0] = i;
        else if (s[i - 1] == 'K') ++sum[i][1], sub[++kcnt][1] = i;
        else ++sum[i][2], sub[++ocnt][2] = i;
    }

    int (&f)[ycnt + 3][kcnt + 3][ocnt + 3][2] = decltype(f)(pool);
    rep(i, ycnt + 1) rep(j, kcnt + 1) rep(k, ocnt + 1) rep(t, 2) f[i][j][k][t] = INF;

    auto query = [&] (int x, int y, int z, int st) {
        int &sb = (st == 0 ? sub[x][0] : (st == 1 ? sub[y][1] : sub[z][2]));
        return sb - min(x, sum[sb][0]) - min(y, sum[sb][1]) - min(z, sum[sb][2]);
    };

    f[0][0][0][0] = 0;
    rep(i, ycnt + 1) rep(j, kcnt + 1) rep(k, ocnt + 1) {
        auto &fk = f[i][j][k][0];
        auto fm = min(f[i][j][k][0], f[i][j][k][1]);
        chmin(f[i + 1][j][k][1], fm + query(i + 1, j, k, 0));
        chmin(f[i][j + 1][k][0], fk + query(i, j + 1, k, 1));
        chmin(f[i][j][k + 1][0], fm + query(i, j, k + 1, 2));
    }

    printf("%d\n", min(f[ycnt][kcnt][ocnt][0], f[ycnt][kcnt][ocnt][1]));
    return 0;
}
