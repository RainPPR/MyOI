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

constexpr int N = 50;

int a[N][N];

signed main() {
    int n = rr, tar = n >> 1;
    int x = 0, y = 0;
    int dir = 0, tot = 0;
    // dir: 0R 1D 2L 3U
    while (x != tar || y != tar) {
        a[x][y] = ++tot;
        if (tot >= n * n) break;
        if (dir == 0) {
            if (y == n - 1 || a[x][y + 1]) dir = 1, ++x;
            else ++y;
        } else if (dir == 1) {
            if (x == n - 1 || a[x + 1][y]) dir = 2, --y;
            else ++x;
        } else if (dir == 2) {
            if (y == 0 || a[x][y - 1]) dir = 3, --x;
            else --y;
        } else if (dir == 3) {
            if (x == 0 || a[x - 1][y]) dir = 0, ++y;
            else --x;
        } else throw "UNKNOWN ERROR";
    } rep(i, n) rep(j, n)
    if (a[i][j])
    printf("%d%c", a[i][j], " \n"[j == n - 1]);
    else printf("T ");
    return 0;
}