#include <bits/stdc++.h>

using namespace std;

void solev() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    int target = 1e9;
    for (int &i : a) cin >> i, target = min(target, i);
    for (int &i : b) cin >> i, target = min(target, i);
    long long int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i], y = b[i];
        ans += max(x, y) - min(x, y);
        ans += min(x, y) - target;
    }
    cout << ans << endl;
}

signed main() {
    int T; cin >> T;
    while (T--) solev();
    return 0;
}