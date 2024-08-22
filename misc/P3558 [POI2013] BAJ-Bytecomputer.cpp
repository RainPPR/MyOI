// Author: RainPPR
// Datetime: 2024-08-22 16:54

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

constexpr int N = 1e6 + 10;

int n;

struct node {
	int a[3];
	int &operator [](int x) {
		return a[x + 1];
	}
} F[N];

void Main() {
	cin >> n;
	F[1][-1] = 1e9;
	F[1][0] = 1e9;
	F[1][1] = 1e9;
	int x;
	cin >> x;
	F[1][x] = 0;
	for (int i = 2; i <= n; ++i) {
		cin >> x;
		if (x == -1) {
			F[i][-1] = F[i - 1][-1];
			F[i][0] = 1e9;
			F[i][1] = F[i - 1][1] + 2;
		}
		if (x == 0) {
			F[i][-1] = F[i - 1][-1] + 1;
			F[i][0] = min(F[i - 1][0], F[i - 1][-1]);
			F[i][1] = F[i - 1][1] + 1;
		}
		if (x == 1) {
			F[i][-1] = F[i - 1][-1] + 2;
			F[i][0] = F[i - 1][-1] + 1;
			F[i][1] = min({F[i - 1][-1], F[i - 1][0], F[i - 1][1]});
		}
	}
	int ans = min({F[n][-1], F[n][0], F[n][1]});
	if (ans >= 1e9) {
		puts("BRAK");
		return;
	}
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
