// Source: Âå¹È
// Problem: P9869 [NOIP2023] ÈýÖµÂß¼­
// Algorithm:
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Author: RainPPR
// Datetime: 2024-08-08 19:44

#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1

#define D(x) ({ void(0); })
#else
#define D(x) ({ auto t = (x); cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << t << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

template<typename T>
ostream &operator <<(ostream &out, vector<T> x) {
	for (T &i : x)
		out << i;
	return out;
}

struct tbin {
	int v; // 0 false, 1 true, 2 uke
	tbin(): v(0) {}
	tbin(int v): v(v) {}
	friend tbin operator !(const tbin &x) {
		if (x.v == 2)
			return 2;
		return !x.v;
	}
	friend bool operator ==(const tbin &x, const tbin &y) {
		return x.v == y.v;
	}
	friend ostream &operator<< (ostream &out, tbin x) {
		if (x.v == 2)
			out << "U";
		else
			out << (x.v ? "T" : "F");
		return out;
	}
};

// -----------------------------------------------------------------------------

constexpr int N = 1e5 + 10;

int c, T;

// -----------------------------------------------------------------------------

namespace s12 {
	int n, m;

	struct opt {
		char op;
		int i, j;
	} q[N];

	int calc() {
		cin >> n >> m;
		for (int i = 1; i <= m; ++i) {
			cin >> q[i].op;
			if (isalpha(q[i].op))
				cin >> q[i].i;
			else
				cin >> q[i].i >> q[i].j;
		}
		int ans = 1e5;
		for (int u = 0; u < (1 << n); ++u)
			for (int v = 0; v < (1 << n); ++v) {
				vector<tbin> arr(n + 1);
				for (int i = 1; i <= n; ++i) {
					int x = u >> (i - 1);
					int y = v >> (i - 1);
					if (x & 1)
						arr[i] = 2;
					else
						arr[i] = y & 1;
				}
				const vector<tbin> bak = arr;
				for (int i = 1; i <= m; ++i) {
					if (q[i].op == 'U')
						arr[q[i].i] = 2;
					else if (isalpha(q[i].op))
						arr[q[i].i] = q[i].op == 'T';
					else if (q[i].op == '+')
						arr[q[i].i] = arr[q[i].j];
					else
						arr[q[i].i] = !arr[q[i].j];
				}
				if (arr == bak) {
					ans = min(ans, __builtin_popcount(u));
				}
			}
		return ans;
	}

	void Main() {
		while (T--) {
			cout << calc() << endl;
		}
	}
}

namespace s34 {
	int calc() {
		int n, m;
		cin >> n >> m;
		vector<tbin> a(n + 1);
		for (int i = 1; i <= m; ++i) {
			char op;
			cin >> op;
			int j;
			cin >> j;
			if (op == 'U')
				a[j] = 2;
			else
				a[j] = op == 'T';
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += a[i].v == 2;
		return ans;
	}

	void Main() {
		while (T--) {
			cout << calc() << endl;
		}
	}
}

namespace s56 {
	vector<int> g[N];

	int vis[N];

	void fill(vector<tbin> &a, int u) {
		if (vis[u])
			return;
		vis[u] = 1;
		a[u] = 2;
		for (int v : g[u])
			fill(a, v);
	}

	int calc() {
		int n, m;
		cin >> n >> m;
		vector<tbin> a(n + 1);
		vector<int> tb;
		for (int i = 1; i <= m; ++i) {
			char op;
			cin >> op;
			int j;
			cin >> j;
			if (op == 'U') {
				a[j] = 2;
				tb.push_back(j);
			}
			else {
				int k;
				cin >> k;
				a[j] = a[k];
				g[k].push_back(j);
			}
		}
		memset(vis, 0, sizeof vis);
		for (int i : tb)
			if (a[i].v == 2)
				fill(a, i);
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += a[i].v == 2, g[i].clear();
		return ans;
	}

	void Main() {
		while (T--) {
			cout << calc() << endl;
		}
	}
}

// -----------------------------------------------------------------------------

signed main() {
#ifdef FAST_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	cin >> c >> T;
	switch (c) {
		case 1:
		case 2:
			s12::Main();
			break;
		case 3:
		case 4:
			s34::Main();
			break;
		case 5:
		case 6:
			s56::Main();
			break;
		default:
			exit(1);
			break;
	}
	return 0;
}
