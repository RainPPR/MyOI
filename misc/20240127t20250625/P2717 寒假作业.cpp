#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
constexpr int K = 1e4 + 10;

int n, k, s[N];

#define range(x) x.begin(), x.end()
#define lowbit(x) ((x) & -(x))

void add(int x) {
    for (; x <= n + k; x += lowbit(x)) ++s[x];
}

int sum(int x) {
    int r = 0;
    for (; x; x -= lowbit(x)) r += s[x];
    return r;
}

signed main() {
    cin >> n >> k;
    vector<int> a(n + 1), p(n);
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1] - k, p[i - 1] = a[i];
    sort(range(p)), p.erase(unique(range(p)), p.end());
    long long ans = 0; int t;
    for (int i = 0; i <= n; ++i) t = lower_bound(range(p), a[i]) - p.begin() + 1, ans += sum(t), add(t);
    cout << ans << endl;
    return 0;
}