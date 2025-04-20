#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

signed main() {
    int T; scanf("%d", &T);
    while (T--) {
        int x, y; scanf("%d%d", &x, &y);
        y -= (y + 6) / 7;
        printf(y >= x ? "YES\n" : "NO\n");
    } return 0;
}
