#include <bits/stdc++.h>

using namespace std;

#define rep(i, l, r) for (decltype(r) i = (l); i <= (r); ++i)
#define lowbit(x) ((x) & -(x))

using ll = long long;

constexpr int N = 2e5 + 10;

ll s[N];

ll query(int x) {
	ll r = 0;
	for (; x; x -= lowbit(x)) r = max(r, s[x]);
	return r;
}

void modify(int x, ll t) {
	for (; x < N; x += lowbit(x)) s[x] = max(s[x], t);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; ll ans = 0; cin >> n;
	vector<int> h(n + 1), a(n + 1);
	rep (i, 1, n) cin >> h[i];
	rep (i, 1, n) cin >> a[i];
	rep (i, 1, n) {
		ll t = query(h[i]) + a[i];
		modify(h[i], t);
		ans = max(ans, t);
	} cout << ans << endl;
	return 0;
}
