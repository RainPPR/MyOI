#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = l; i < r; ++i)

#define dg(c) isdigit(c)
#define gc() getchar_unlocked()
#define endl '\n'

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !dg(c); c = gc()) f |= c == '-';
    for (; dg(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

using ll = long long;
using db = double;

db solve(int n, int k) {
    vector<vector<db>> f(n + 1, vector<db>(n + 1));
    gor(i, 1, n + 1) rep(j, n + 1) {
        if (i >= j) f[i][j] = j;
        else if (i <= k) f[i][j] = 0;
        else {
            rep(t, n + 1) f[i][j] += f[i - k][t];
            f[i][j] /= n + 1;
        }
    } db res = 0; rep(j, n + 1) {
        db t = 0;
        gor(i, 1, n + 1) t += f[i][j];
        res = max(res, t);
    } return res;
}

signed main() {
    int n = rr, k = rr;
    if (k == 0) {
        printf("%lld\n", 1ll * n * (n + 1) / 2);
    } else if (k == n) {
        printf("%d\n", n);
    } else {
        printf("%lf\n", solve(n, k));
    } return 0;
}
