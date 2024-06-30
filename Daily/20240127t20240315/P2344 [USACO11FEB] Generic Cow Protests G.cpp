#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
constexpr int mod = 1e9 + 9;

int n, s[N];

#define range(x) x.begin(), x.end()
#define lowbit(x) ((x) & -(x))

void add(int x, int v) {
    for (; x <= n; x += lowbit(x)) s[x] = (s[x] + v) % mod;
}

int sum(int x) {
    int r = 0;
    for (; x; x -= lowbit(x)) r = (r + s[x]) % mod;
    return r;
}

signed main() {
    cin >> n; vector<int> a(n + 1), p(n);
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1], p[i - 1] = a[i];
    p.push_back(0);
    sort(range(p)), p.erase(unique(range(p)), p.end());
    int ans = 0, t; add(lower_bound(range(p), 0) - p.begin() + 1, 1);
    for (int i = 1; i <= n; ++i) t = lower_bound(range(p), a[i]) - p.begin() + 1, ans = sum(t), add(t, ans);
    cout << ans << endl;
    return 0;
}