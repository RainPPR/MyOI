#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 1010;

int n, w[N];

int m, q[N];

void Main() {
	cin >> n >> m;
	copy_n(istream_iterator<int>(cin), n, w + 1);
	copy_n(istream_iterator<int>(cin), m, q + 1);
	unordered_set<int> app;
	vector<int> p{0};
	for (int i = 1; i <= m; ++i)
		if (!app.count(q[i])) {
			p.push_back(q[i]);
			app.insert(q[i]);
		}
	long long ans = 0;
	for (int i = 1; i <= m; ++i) {
		int x = q[i], j = 1;
		for (; p[j] != x; ++j)
			ans += w[p[j]];
		for (; j > 1; --j)
			p[j] = p[j - 1];
		p[1] = x;
	}
	cout << ans << endl;
	return;
}

signed main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

