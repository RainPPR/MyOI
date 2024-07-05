#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n; vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(range(a), greater<int>()); n = min(n, 40); int ans = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j)
    ans = max(ans, a[i] & a[j]);
    cout << ans << endl;
    return 0;
}
