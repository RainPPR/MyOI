// Source: Âå¹È
// Problem: P9117 [´º¼¾²âÊÔ 2023] Í¿É«ÓÎÏ·
// Algorithm: Ä£Äâ
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Author: RainPPR
// Datetime: 2024-08-10 09:50

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

// -----------------------------------------------------------------------------

constexpr int N = 1e5 + 10;

struct node {
	int col, dfn;
};

void Main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, q;
		cin >> n >> m >> q;
		vector<node> a(n + 1), b(m + 1);
		for (int i = 1; i <= q; ++i) {
			int op, x, c;
			cin >> op >> x >> c;
			(op ? b : a)[x] = {c, i};
		}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				cout << (a[i].dfn > b[j].dfn ? a[i].col : b[j].col);
				cout << " \n"[j == m];
			}
	}
	return;
}

// -----------------------------------------------------------------------------

signed main() {
#ifdef FAST_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	Main();
	return 0;
}
