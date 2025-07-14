// Author: RainPPR
// Datetime: 2024-08-22 15:02

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

constexpr int N = 3e3 + 10;

void init_matching(int n, int *A, int k, int *C, int *P) {
	for (int i = 1; i + k - 1 <= n; ++i) {
		int p = i, q = 1;
		while (p <= n && q <= k) {
			q += (A[p] == C[q]);
			++p;
		}
		P[i] = (q > k) ? p - 1 : 0;
	}
}

int n, A[N], P[N];
int m, B[N], Q[N];
int k, C[N];
int F[N][N], G[N][N];

void init_LCS() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (A[i] == B[j])
				F[i][j] = F[i - 1][j - 1] + 1;
			else
				F[i][j] = max(F[i][j - 1], F[i - 1][j]);
}

void init_rLCS() {
	for (int i = n; i >= 1; --i)
		for (int j = m; j >= 1; --j)
			if (A[i] == B[j])
				G[i][j] = G[i + 1][j + 1] + 1;
			else
				G[i][j] = max(G[i][j + 1], G[i + 1][j]);
}

int get_ans() {
	int Ans = -1;
	for (int i = 1; i + k - 1 <= n; ++i)
		for (int j = 1; j + k - 1 <= m; ++j)
			if (P[i] && Q[j])
				Ans = max(Ans, F[i - 1][j - 1] + G[P[i] + 1][Q[j] + 1] + k);
	return Ans;
}

void Main() {
	cin >> n;
	copy_n(istream_iterator<int>(cin), n, A + 1);
	cin >> m;
	copy_n(istream_iterator<int>(cin), m, B + 1);
	cin >> k;
	copy_n(istream_iterator<int>(cin), k, C + 1);
	init_matching(n, A, k, C, P);
	init_matching(m, B, k, C, Q);
	init_LCS(), init_rLCS();
	cout << get_ans() << endl;
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
