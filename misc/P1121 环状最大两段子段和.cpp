// Author: RainPPR
// Datetime: 2024-08-23 10:01

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

template<int emp>
int calc(int n, int *A, function<int(int, int)> cmp) {
	static int F[N], G[N];
	F[0] = G[n + 1] = emp;
	int Ans = emp;
	for (int i = 1; i <= n; ++i)
		F[i] = cmp(F[i - 1], 0) + A[i];
	for (int i = 1; i <= n; ++i)
		F[i] = cmp(F[i], F[i - 1]);
	for (int i = n; i >= 1; --i)
		G[i] = cmp(G[i + 1], 0) + A[i];
	for (int i = n; i >= 1; --i)
		G[i] = cmp(G[i], G[i + 1]);
	for (int i = 2; i < n; ++i)
		Ans = cmp(Ans, F[i - 1] + G[i + 1]);
	return Ans;
}

int n, Sum, A[N];

void Main() {
	cin >> n, Sum = 0;
	for (int i = 1; i <= n; ++i)
		cin >> A[i], Sum += A[i];
	auto Max = [] (int a, int b) {
		return max(a, b);
	};
	auto Min = [] (int a, int b) {
		return min(a, b);
	};
	int Ans = calc < (int) -1e9 > (n, A, Max);
	Ans = max(Ans, Sum - calc < 0 > (n - 1, A, Min));
	Ans = max(Ans, Sum - calc < 0 > (n - 1, A + 1, Min));
	cout << Ans << endl;
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
