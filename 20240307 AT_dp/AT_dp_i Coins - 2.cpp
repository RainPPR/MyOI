#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3010;

int n; double p[N], f[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n; for (int i = 1; i <= n; ++i) cin >> p[i];
	f[0] = 1; for (int i = 1; i <= n; f[0] = f[0] * (1 - p[i++])) for (int j = n; j; --j) f[j] = f[j] * (1 - p[i]) + f[j - 1] * p[i];
	double ans = 0; for (int i = n + 1 >> 1; i <= n; ++i) ans += f[i];
	printf("%.10lf\n", ans);
	return 0;
}
