#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void Main();

void Main(int T) {
	cin >> T;
	while (T--)
		Main();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

using i2 = __int128;

template<typename T>
T mygcd(T a, T b) {
	return b ? mygcd(b, a % b) : a;
}

template<typename T>
T mylcm(T a, T b) {
	return a / mygcd(a, b) * b;
}

void print(i2 T, char ed = '\n') {
	if (T == 0)
		cout << 0 << ed;
	else {
		static int res[100];
		int tot = 0;
		while (T) {
			res[++tot] = T % 10;
			T /= 10;
		}
		for (int i = tot; i >= 1; --i)
			cout << res[i];
		cout << ed;
	}
}

constexpr int N = 1e5 + 10;

int n, m;

int in[N], out[N];

vector<int> G[N];

struct frac {
	i2 p, q; // p / q

	frac() = default;
	frac(i2 a, i2 b) {
		if (a == 0 && b == 0)
			p = q = 0;
		else {
			i2 g = mygcd(a, b);
			p = a / g, q = b / g;
		}
	}

	void print() {
		::print(p, ' ');
		::print(q, '\n');
	}

	friend frac operator /(const frac &a, const int &b) {
		return frac(a.p, a.q * b);
	}

	friend frac operator +(const frac &a, const frac &b) {
		if (a.p == 0 || b.q == 0)
			return b;
		if (b.p == 0 || b.q == 0)
			return a;
		i2 tar = mylcm(a.q, b.q);
		return frac(a.p * (tar / a.q) + b.p * (tar / b.q), tar);
	}
} ans[N];

void solve() {
	queue<int> q;
	for (int i = 1; i <= m; ++i)
		q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (out[u] == 0)
			continue;
		frac ad = ans[u] / out[u];
		for (int v : G[u]) {
			ans[v] = ans[v] + ad;
			if (--in[v] == 0)
				q.push(v);
		}
	}
}

void Main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		ans[i] = frac(1, 1);
	vector<int> ed;
	for (int i = 1; i <= n; ++i) {
		cin >> out[i];
		if (out[i] == 0)
			ed.push_back(i);
		G[i].resize(out[i]);
		for (int &j : G[i])
			cin >> j, ++in[j];
	}
	solve();
	for (int i : ed)
		ans[i].print();
	return;
}

