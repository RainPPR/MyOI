#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

#define multi(op) [] { int T; cin >> T; while (T--) op(); }

auto Main = ([] {
	int n;
	cin >> n;
	vector<int> a;
	while (n--) {
		int x;
		cin >> x;
		if (x)
			a.push_back(x);
	}
	if (a.empty()) {
		cout << 0 << endl;
		return;
	}
	sort(a.begin(), a.end());
	if (a.front() > 0 || a.back() < 0) {
		cout << a.back() << endl;
		return;
	}
	int x = a.back();
	a.pop_back();
	bitset<8000000> dp;
	for (auto i : a) {
		if (i > 0)
			dp |= dp << i;
		else
			dp |= dp >> -i;
		dp.set(i + 4000000);
	}
	int res = -1e9;
	for (int i = 0; i <= 4000000; ++i)
		if (dp[i])
			res = i;
	cout << res - 4000000 + x << endl;
	return;
});

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

