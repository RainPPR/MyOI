#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void Main();

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

struct edge {
	int u, v, w;
	edge() = default;
	edge(int u, int v, int w): u(u), v(v), w(w) {}
	friend bool operator <(const edge &a, const edge &b) {
		return a.w < b.w;
	}
};

vector<edge> G;

constexpr int N = 3e5 + 10;

int n, m;

int f[N], g[N], last[N];

int calc() {
	sort(G.begin(), G.end());
	for (auto t : G) {
		int u = t.u, v = t.v, w = t.w;
		int e = last[u] == w ? g[u] + 1 : f[u] + 1;
		if (f[v] >= e)
			continue;
		if (last[v] != w)
			g[v] = f[v];
		f[v] = e, last[v] = w;
	}
	return *max_element(f + 1, f + n + 1);
}

void Main() {
	cin >> n >> m;
	G.reserve(m);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G.emplace_back(u, v, w);
	}
	cout << calc() << endl;
	return;
}
