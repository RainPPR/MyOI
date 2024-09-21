// Author: RainPPR
// Datetime: 2024-09-16 13:03

#ifndef M_DEBUG
//#define NDEBUG 1
#define FAST_IO 1

#define D(x) ({ void(0); })
#else
#define D(x) ({ auto t = (x); cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << t << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef __linux__
#include <bits/extc++.h>
#define gc() getchar_unlocked()
#else
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/exception.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/list_update_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define gc() getchar()
#endif

using namespace std;

#ifdef FAST_IO
#define endl "\n"
#endif

template<typename T>

T read() {
	T n = 0;
	int f = 0, c = gc();
	for (; !isdigit(c); c = gc())
		f |= c == '-';
	for (; isdigit(c); c = gc())
		n = n * 10 + c - '0';
	return f ? -n : n;
}

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

template<typename T, typename CMP = less<T>>
using pqueue = __gnu_pbds::priority_queue<T, CMP>;
// using pqueue = priority_queue<T, vector<T>, CMP>;

// -----------------------------------------------------------------------------

using ll = long long;

#define int ll

int a, b, c, d;

vector<pair<int, int>> ans;

void work(int x, int y) {
	ans.emplace_back(x, y);
	if (x == 1) {
		assert(y <= a);
		a /= y;
		b *= y;
	}
	else {
		assert(y <= b);
		b /= y;
		a *= y;
	}
}

void print() {
	cout << ans.size() << endl;
	for (auto t : ans)
		cout << t.first << " " << t.second << endl;
}

int Main(int _) {
	_ = _;
	cin >> a >> b >> c >> d;
	if (a * b < c * d)
		return -1;
	if (c * d == 1)
		return (a * b == 1) - 1;
	ans.clear(), work(1, a);
	while (a * b >= 2 * c * d) {
		int v = a * b / 2 + 1;
		if (a != 1)
			work(1, v);
		else
			work(2, v);
	}
	if (a != 1)
		work(1, a);
	work(2, c * d);
	work(1, d);
	return print(), 1;
}

void Main() {
	int T;
	cin >> T;
	while (T--) {
		int res = Main(T);
		if (res != 1)
			cout << res << endl;
	}
}

// -----------------------------------------------------------------------------

signed main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#ifdef FAST_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	Main();
	return 0;
}

/*
-DM_DEBUG
-std=c++14
-Ofast -ffast-math
-Wall -Wextra -Wshadow -Wfloat-equal
-Wl,--stack=1024000000
*/