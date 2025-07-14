#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, a[1010][1010];

void Main() {
    cin >> n;
    auto filll = [] (int i, int j) {
        static int cnt = 0;
        for (int x = 0; x < 4; ++x)
            for (int y = 0; y < 4; ++y)
                a[i + x][j + y] = cnt++;
    };
    for (int i = 1; i <= n; i += 4)
        for (int j = 1; j <= n; j += 4)
            filll(i, j);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << " \n"[j == n];
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}
