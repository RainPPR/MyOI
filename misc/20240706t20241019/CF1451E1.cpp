// Author: RainPPR
// Datetime: 2024-09-30 12:35

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

constexpr int N = 1 << 17;

int xrr[N];

int g_add(int a, int b) {
	cout << "AND " << a << " " << b << endl;
	cout.flush();
	int x;
	cin >> x;
	int e = xrr[a];
	for (int i = a + 1; i < b; ++i)
		e ^= xrr[i];
	return x * 2 + e;
}

int g_xor(int a, int b) {
	cout << "XOR " << a << " " << b << endl;
	cout.flush();
	int x;
	cin >> x;
	return x;
}

void Main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i)
		xrr[i] = g_xor(i, i + 1);
	vector<int> a(n + 1);
	a[2] = (g_add(1, 2) + g_add(2, 3) - g_add(1, 3)) >> 1;
	a[1] = xrr[1] ^ a[2];
	for (int i = 3; i <= n; ++i)
		a[i] = xrr[i - 1] ^ a[i - 1];
	cout << "! ";
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	cout.flush();
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