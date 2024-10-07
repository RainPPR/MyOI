#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

#define int ll

int n, a[100];

int calc() {
    int b[3] = {a[1], a[2], a[3]};
    sort(b, b + 3);
    int now = b[2] - b[0];
    if (now > b[1])
        return 1;
    if (now == b[1])
        return 2;
    return 3;
}

void Main() {
    int T;
    cin >> T;
    cin >> n;
    assert(n == 3);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << calc() << endl;
    while (--T) {
        int k;
        cin >> k;
        while (k--) {
            int x, y;
            cin >> x >> y;
            a[x] = y;
        }
        cout << calc() << endl;
    }
    return;
}

signed main() {
    // freopen("snake.in", "r", stdin);
    // freopen("snake.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}