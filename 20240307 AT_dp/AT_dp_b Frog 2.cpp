#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<int> a(n); for (int &i : a) cin >> i;
	vector<int> f(n, 0x3f3f3f3f); f[0] = 0;
	for (int i = 1; i < n; ++i) for (int j = 1; j <= k && j <= i; ++j) f[i] = min(f[i], f[i - j] + abs(a[i] - a[i - j]));
	cout << f[n - 1] << endl;
	return 0;
}
