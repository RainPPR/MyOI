#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void Main();

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

using ll = long long;

#define int ll

constexpr int N = 1e5 + 10;

int n, a[N], d[N], s[N];

int calc(int x) {
	int p = upper_bound(d, d + n, x) - d;
	return n + x + s[p - 1] + (n - p) * x;
}

void Main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; ++i)
		d[i] = a[i + 1] - a[i] - 1;
	sort(d + 1, d + n);
	for (int i = 1; i < n; ++i)
		s[i] = s[i - 1] + d[i];
	int T;
	cin >> T;
	while (T--) {
		int l, r;
		cin >> l >> r;
		cout << calc(r - l) << " ";
	}
	return;
}
