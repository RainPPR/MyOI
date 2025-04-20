// Source: Âå¹È
// Problem: P9752 [CSP-S 2023] ÃÜÂëËø
// Algorithm: Ä£Äâ
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Author: RainPPR
// Datetime: 2024-08-09 09:09

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

struct mlock {
	array<int, 5> a;
	friend bool operator ==(const mlock &x, const mlock &y) {
		return x.a == y.a;
	}
	friend bool operator <(const mlock &x, const mlock &y) {
		return x.a < y.a;
	}
	friend ostream &operator <<(ostream &out, mlock x) {
		for (int i = 0; i < 5; ++i)
			out << x.a[i];
		return out;
	}
	friend mlock op1(mlock x, int i, int j) {
		x.a[i] = (x.a[i] + j) % 10;
		return x;
	}
	friend mlock op2(mlock x, int i, int j) {
		x.a[i] = (x.a[i] + j) % 10;
		x.a[i + 1] = (x.a[i + 1] + j) % 10;
		return x;
	}
};

int Main() {
	int n;
	cin >> n;
	map<mlock, int> bucket;
	for (int i = 1; i <= n; ++i) {
		mlock x;
		for (int j = 0; j < 5; ++j)
			cin >> x.a[j];
		set<mlock> appr;
		for (int k = 1; k < 10; ++k) {
			for (int j = 0; j < 5; ++j)
				appr.insert(op1(x, j, k));
			for (int j = 0; j < 4; ++j)
				appr.insert(op2(x, j, k));
		}
		for (mlock j : appr)
			++bucket[j];
	}
	int ans = 0;
	for (auto t : bucket)
		ans += t.second == n;
	return ans;
}

// -----------------------------------------------------------------------------

signed main() {
#ifdef FAST_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	cout << Main() << endl;
	return 0;
}
