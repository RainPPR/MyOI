#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 2e5 + 10;

int n, fa[N], is_leaf[N];

void push(i, vector<int> &ans) {
	;
}

int tot;

vector<int> ans[N];

void MAIN() {
	cin >> n, tot = 0;
	for (int i = 1; i <= n; ++i)
		is_leaf[i] = true;
	for (int i = 1; i <= n; ++i) {
		cin >> fa[i];
		is_leaf[fa[i]] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		if (!is_leaf[i])
			continue;
		push(i, ans[++tot]);
	}
	cout << tot << endl;
	for (int i = 1; i <= tot; ++i) {
		cout << ans[i].size() << endl;
		for (auto it = ans[i].rbegin(); it != ans[i].rend(); ++i)
			cout << *it << " ";
		cout << endl;
	}
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
