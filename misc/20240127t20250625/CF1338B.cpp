#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 1e5 + 10;

int n;

vector<int> G[N];

int res, bucket[2];

int dfs(int u, int fa, int dep = 0) {
	if (G[u].size() == 1) {
		bucket[dep] = 1;
		return 1;
	}
	int tot = 0;
	for (int v : G[u]) {
		if (v == fa)
			continue;
		tot += dfs(v, u, dep ^ 1);
	}
	res += max(0, tot - 1);
	return 0;
}

void Main() {
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (G[i].size() <= 1)
			continue;
		dfs(i, -1);
		break;
	}
	if (bucket[0] && bucket[1])
		cout << "3 ";
	else
		cout << "1 ";
	cout << n - 1 - res << endl;
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

