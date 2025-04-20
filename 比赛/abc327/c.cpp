#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

#define fail() printf("No\n"), exit(0);

signed main() {
    int mp[9][9];
    rep(i, 9) rep(j, 9) cin >> mp[i][j];

    rep(i, 9) {
        // check row
        int apr[10] = {0};
        rep(j, 9) ++apr[mp[i][j]];
        rep(j, 9) if (apr[j + 1] != 1) fail();
    }

    rep(j, 9) {
        // check col
        int apr[10] = {0};
        rep(i, 9) ++apr[mp[i][j]];
        rep(j, 9) if (apr[j + 1] != 1) fail();
    }

    rep(i, 3) rep(j, 3) {
        int apr[10] = {0};
        rep(p, 3) rep(q, 3)
            ++apr[mp[i * 3 + p][j * 3 + q]];
        rep(j, 9) if (apr[j + 1] != 1) fail();
    }

    printf("Yes\n");
    return 0;
}
