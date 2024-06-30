#include <bits/stdc++.h>

using namespace std;

#define rep(i, l, n) for (int i = l; i <= n; ++i)
#define range(x) x.begin(), x.end()

constexpr int N = 110;
constexpr int K = 1e5 + 10;

constexpr int mod = 1e9 + 7;

int n, k, a[N];
int f[K], sum[K];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> k; rep(i, 1, n) cin >> a[i];
	auto xht = [&] (int l, int r) {
		if (l == 0) return sum[r];
		else return (sum[r] - sum[l - 1] + mod) % mod;
	}; f[0] = 1; rep(i, 1, n) {
		sum[0] = f[0]; rep(j, 1, k) sum[j] = (sum[j - 1] + f[j]) % mod;
		rep(j, 0, k) f[j] = xht(max(0, j - a[i]), j);
	} cout << f[k] << endl;
	return 0;
}
