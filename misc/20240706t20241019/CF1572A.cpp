#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 2e5 + 10;

int n;

struct edge {
	int v, w;
	edge() = default;
	edge(int v, int w): v(v), w(w) {}
};

vector<edge> G[N];

int dis[N], deg[N];

int top_sort() {
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 0)
			q.push(i);
	int ans = 0, tot = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop(), ++tot;
		for (auto t : G[u]) {
			int v = t.v;
			dis[v] = max(dis[v], dis[u] + t.w);
			ans = max(ans, dis[v]);
			if ((--deg[v]) == 0)
				q.push(v);
		}
	}
	return tot != n ? -1 : ans + 1;
}

int MAIN() {
	cin >> n;
	memset(dis, 0, sizeof(int) * (n + 1));
	memset(deg, 0, sizeof(int) * (n + 1));
	for (int i = 1; i <= n; ++i)
		G[i].clear();
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int j;
			cin >> j;
			G[j].emplace_back(i, j > i);
			++deg[i];
		}
	}
	return top_sort();
}

void Main() {
	int T;
	cin >> T;
	while (T--)
		cout << MAIN() << endl;
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

