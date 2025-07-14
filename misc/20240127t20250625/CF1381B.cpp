#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

#define res(cond) ((cond) ? "YES" : "NO")

bool dp(int n, const vector<int> &a) {
	bitset<2010> dp;
	dp.set(0);
	// cout << n << ": ";
	for (int i : a)
		dp |= dp << i;
	// 	cout << i << " ";
	// cout << endl;
	return dp[n];
}

bool dp(int n, const basic_string<int> &a) {
	vector<int> b;
	int last = n;
	for (int i : a) {
		b.push_back(last - i);
		last = i;
	}
	return dp(n >> 1, b);
}

void MAIN() {
	int n;
	cin >> n;
	n <<= 1;
	vector<int> a(n), pre(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pre[i] = i ? max(pre[i - 1], a[i]) : a[i];
	}
	basic_string<int> split;
	split.reserve(n);
	int suf = -1;
	for (int i = n - 1; i >= 0; --i) {
		suf = max(suf, a[i]);
		if (pre[i] == suf) {
			split.push_back(i);
			suf = -1;
		}
	}
	cout << res(dp(n, split)) << endl;
	return;
}

void Main() {
	int T;
	cin >> T;
	while (T--)
		MAIN();
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

