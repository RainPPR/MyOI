#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

signed main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        vector<int> a(n);
        rep(i, n) scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        ll p = 0, q = 0;
        rep(i, n) (i % 2 == 0 ? p : q) += a[i];
        printf("%lld\n", abs(p - q));
    } return 0;
}
