#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) ((x) & -(x))
#define range(x) x.begin(), x.end()

using ll = long long;

constexpr int N = 1e6 + 10;

int tot, e[N];

void insert(int x) {
    for (; x <= tot; x += lowbit(x)) ++e[x];
}

int query(int x) {
    int r = 0;
    for (; x; x -= lowbit(x)) r += e[x];
    return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n; vector<int> a(n), rk(n);
    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; ++i) cin >> a[i], s[i] = {a[i], i};
    sort(range(s)); tot = unique(range(s)) - s.begin();
    for (int i = 0; i < n; ++i) rk[s[i].second] = i + 1;
    ll ans = 0;
    for (int i = n - 1; ~i; --i) insert(rk[i]), ans += query(rk[i] - 1);
    cout << ans << endl;
    return 0;
}
