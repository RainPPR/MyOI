// Author: RainPPR
// Datetime: 2024-08-17 17:03

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

constexpr int N = 2e5 + 10;

using u64 = uint64_t;

mt19937_64 rnd_big(114514);

int n;

u64 W[N];

u64 A[N], B[N];

unordered_set<int> appA, appB;
unordered_map<int, u64> hashing;

u64 get_hashing(int x) {
	return hashing.count(x) ? hashing[x] : hashing[x] = rnd_big();
}

void Main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (appA.count(x))
			A[i] = A[i - 1];
		else
			A[i] = A[i - 1] ^ get_hashing(x), appA.insert(x);
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (appB.count(x))
			B[i] = B[i - 1];
		else
			B[i] = B[i - 1] ^ get_hashing(x), appB.insert(x);
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		puts(A[x] == B[y] ? "Yes" : "No");
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