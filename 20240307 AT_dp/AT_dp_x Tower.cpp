#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < n; ++i)

#define endl '\n'
#define ERR { puts("No"), exit(0); }

struct emm {
	int w, s, v;
	friend bool operator <(const emm &a, const emm &b) {
		return min(a.s, b.s - a.w) > min(b.s, a.s - b.w);
	}
};

using ll = long long;
constexpr int M = 2e4 + 10;

ll dp[M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n; vector<emm> a(n);
	for (auto &[w, s, v] : a) cin >> w >> s >> v;
	sort(a.begin(), a.end());
	for (auto &[w, s, v] : a) for (int i = s; ~i; --i) dp[i + w] = max(dp[i + w], dp[i] + v);
	cout << *max_element(dp, dp + M) << endl;
	return 0;
}
