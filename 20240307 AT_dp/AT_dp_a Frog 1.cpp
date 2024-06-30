#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n; vector<int> a(n);
	for (int &i : a) cin >> i;
	vector<int> f(n); f[1] = abs(a[1] - a[0]);
	for (int i = 2; i < n; ++i) f[i] = min(f[i - 1] + abs(a[i] - a[i - 1]), f[i - 2] + abs(a[i] - a[i - 2]));
	cout << f[n - 1] << endl;
	return 0;
}
