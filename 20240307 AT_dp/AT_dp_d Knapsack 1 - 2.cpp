#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

constexpr int N = 110;
constexpr int M = 1e5 + 10;

int n, W;
int w[N], v[N];

ll f[M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> W; rep(i, n) cin >> w[i] >> v[i];
	for (int i = w[0]; i <= W; ++i) f[i] = v[0];
	for (int i = 1; i < n; ++i) for (int j = W; j >= w[i]; --j) f[j] = max(f[j], f[j - w[i]] + v[i]);
	cout << *max_element(f, f + W + 1) << endl;
	return 0;
}
