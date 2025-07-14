// Author: RainPPR
// Datetime: 2024-08-20 20:02

#ifndef M_DEBUG
#define NDEBUG 1
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

constexpr int N = 1e4 + 10;

int n, m;

struct node {
	int t, x, y;
} a[N];

int F[N];

int dis(int i, int j) {
	return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
}

bool check(int j, int i) {
	return dis(i, j) <= abs(a[i].t - a[j].t);
}

void Main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> a[i].t >> a[i].x >> a[i].y;
	for (int i = 1; i <= m; ++i) {
		F[i] = 1;
		for (int j = 1; j < i; ++j)
			if (check(j, i))
				F[i] = max(F[i], F[j] + 1);
	}
	int ans = F[1];
	for (int i = 2; i <= m; ++i)
		ans = max(ans, F[i]);
	cout << ans << endl;
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
