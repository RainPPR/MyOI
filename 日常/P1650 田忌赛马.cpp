// Author: RainPPR
// Datetime: 2024-08-19 18:39

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

int n;
int A[2010], B[2010];
int F[2010][2010];

inline int G(int x, int y) {
	if (A[x] > B[y])
		return 200;
	if (A[x] < B[y])
		return -200;
	return 0;
}

void Main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> A[i];
	for (int i = 1; i <= n; ++i)
		cin >> B[i];
	sort(A + 1, A + n + 1);
	sort(B + 1, B + n + 1);
	for (int i = 1; i <= n; ++i) {
		F[i][0] = F[i - 1][0] + G(i, n - i + 1);
		F[i][i] = F[i - 1][i - 1] + G(i, i);
		for (int j = 1; j < i; ++j)
			F[i][j] = max(F[i - 1][j] + G(i, n - (i - j) + 1), F[i - 1][j - 1] + G(i, j));
	}
	int Ans = -1e9;
	for (int i = 0; i <= n; ++i)
		Ans = max(Ans, F[n][i]);
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
