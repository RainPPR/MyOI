// Author: RainPPR
// Datetime: 2024-08-19 19:10

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

int n, m;

int A[400], mem[40][40][40][40];

int dfs(int x, int a, int b, int c, int d) {
	if (a < 0 || b < 0 || c < 0 || d < 0)
		return -1e9;
	if (x > n)
		return -1e9;
	if (x == n)
		return A[n];
	if (mem[a][b][c][d] != -1)
		return mem[a][b][c][d];
	return mem[a][b][c][d] = max({
		mem[a][b][c][d],
		dfs(x + 1, a - 1, b, c, d),
		dfs(x + 2, a, b - 1, c, d),
		dfs(x + 3, a, b, c - 1, d),
		dfs(x + 4, a, b, c, d - 1)
	}) + A[x];
}

void Main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> A[i];
	int C[5] = {0};
	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		++C[x];
	}
	memset(mem, -1, sizeof mem);
	cout << dfs(1, C[1], C[2], C[3], C[4]) << endl;
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
