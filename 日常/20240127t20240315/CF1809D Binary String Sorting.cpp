#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll op_c = ll(1e12);
ll op_d = ll(1e12) + 1;

ll solev() {
	string str; cin >> str; int n = str.size();
	vector<int> pre1(n + 2), suf0(n + 2);
	for (int i = 1; i <= n; ++i) pre1[i] = pre1[i - 1] + (str[i - 1] == '1');
	for (int i = n; i >= 1; --i) suf0[i] = suf0[i + 1] + (str[i - 1] == '0');
	ll ans = pre1[n];
	for (int i = 1; i <= n; ++i) ans = min(ans, 1ll * pre1[i - 1] + suf0[i]);
	ans *= op_d;
	for (int i = 1; i < n; ++i) if (str[i - 1] == '1' && str[i] == '0')
	ans = min(ans, op_c + (pre1[i - 1] + suf0[i + 2]) * op_d);
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while (T--) cout << solev() << endl;
	return 0;
}