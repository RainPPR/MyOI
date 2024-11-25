#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 1e5 + 10;

using ll = long long;

#define int ll

string n;

int m, v[10];

int dp[N][14];

int poww[N];

int MAIN() {
	cin >> n;
	m = n.size();
	n = "#" + n;
	for (int i = 1; i <= 9; ++i)
		cin >> v[i];
	memset(dp, 0x3f, sizeof dp);
	dp[m + 1][0] = 0;
	for (int i = m; i >= 1; --i) {
		dp[i][0] = dp[i + 1][0] + v[n[i] - '0'];
		for (int j = 1; j <= m - i + 1 && j <= 13; ++j)
			dp[i][j] = min(
				dp[i + 1][j] + v[n[i] - '0'],
				dp[i + 1][j - 1] + poww[j - 1] * (n[i] - '0')
			);
	}
	int ans = 1e18;
	for (int j = 0; j <= m && j <= 13; ++j)
		ans = min(ans, dp[1][j]);
	return ans;
}

void Main() {
	poww[0] = 1;
	for (int i = 1; i <= 12; ++i)
		poww[i] = poww[i - 1] * 10;
	// cerr << poww[12] << endl;
	int op, T;
	cin >> op >> T;
	while (T--)
		cout << MAIN() << endl;
	return;
}

signed main() {
//    freopen("bargain5.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

