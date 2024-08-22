#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define rr read()

inline int read() {
    int n = 0, c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

int main() {
    int n = rr; vector<int> b(n, 1e9);
    vector<vector<int>> c(n, vector<int>(n));
    rep(i, n) rep(j, n) c[i][j] = rr, b[j] = min(b[j], c[i][j]);
    rep(i, n) rep(j, n) {
        c[i][j] -= b[j];
        if (c[i][j] != c[i][0])printf("No"), exit(0);
    }
    rep(i, n) printf("%d%c", c[0][i], " \n"[i == n - 1]);
    rep(i, n) printf("%d%c", b[i], " \n"[i == n - 1]);
    return 0;
}
