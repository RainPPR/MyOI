// Author: RainPPR
// Datetime: 2024-08-24 20:35

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

using u64 = uint64_t;
using u128 = __uint128_t;

u64 Pow(u64 a, u64 b, u64 p) {
	u64 r = 1;
	for (; b; b >>= 1) {
		if (b & 1)
			r = (u128)r * a % p;
		a = (u128)a * a % p;
	}
	return r;
}

bool Miller_Rabin(u64 a, u64 n, u64 d, int r) {
	u64 k = Pow(a, d, n);
	if (k == 1)
		return true;
	for (int i = 0; i < r; ++i) {
		if (k == n - 1)
			return true;
		k = (u128)k * k % n;
	}
	return false;
}

vector<int> pri{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool isPrime(u64 n) {
	if (n < 3 || n % 2 == 0)
		return n == 2;
	int r = __builtin_ctzll(n - 1);
	u64 d = (n - 1) >> r;
	for (int i : pri) {
		if (n == i)
			return true;
		if (!Miller_Rabin(i, n, d, r))
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	if (n == 1)
		puts("Anna"), exit(0);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		cnt += isPrime(x);
	}
	if (cnt == 0)
		puts(n == 2 ? "Bruno" : "Anna");
	else if (cnt == n - 1)
		puts("Anna");
	else
		puts(n % 2 ? "Anna" : "Bruno"), exit(1);
	return 0;
}
