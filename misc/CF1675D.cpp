#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 2e5 + 10;

int n, fa[N], leaf[N];

int vis[N];

void push(int u, vector<int> &ans) {
	while (!vis[u]) {
		ans.push_back(u);
		vis[u] = true;
		u = fa[u];
	}
}

int tot;

vector<int> ans[N];

void MAIN() {
	cin >> n, tot = 0;
	if (n == 1) {
		cin >> n;
		cout << "1\n1\n1\n" << endl;
		return;
	}
	memset(vis, 0, sizeof(int) * (n + 1));
	memset(leaf, 0, sizeof(int) * (n + 1));
	for (int i = 1; i <= n; ++i) {
		cin >> fa[i];
		leaf[fa[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (leaf[i])
			continue;
		++tot;
		ans[tot].clear();
		push(i, ans[tot]);
	}
	cout << tot << endl;
	for (int i = 1; i <= tot; ++i) {
		cout << ans[i].size() << endl;
		for (auto it = ans[i].rbegin(); it != ans[i].rend(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
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
