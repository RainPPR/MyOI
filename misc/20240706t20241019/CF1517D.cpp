#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 510;

int n, m, K;
int a[N][N], b[N][N];

int ans[N][N];

int dp[N][N][22];

void calc() {
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dp[i][j][0] = 0;
	for (int k = 1; k <= (K >> 1); ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				dp[i][j][k] = min({
					dp[i - 1][j][k - 1] + b[i - 1][j],
					dp[i + 1][j][k - 1] + b[i][j],
					dp[i][j - 1][k - 1] + a[i][j - 1],
					dp[i][j + 1][k - 1] + a[i][j]
				});
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			ans[i][j] = dp[i][j][K >> 1] << 1;
}

void Main() {
	cin >> n >> m >> K;
	if (K & 1)
		memset(ans, -1, sizeof ans);
	else {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j < m; ++j)
				cin >> a[i][j];
		for (int i = 1; i < n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> b[i][j];
		calc();
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cout << ans[i][j] << " \n"[j == m];
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

