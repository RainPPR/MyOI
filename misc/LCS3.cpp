// Author: RainPPR
// Datetime: 2024-08-22 15:47

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

constexpr int N = 110;

int F[N][N][N];

int Main(string A, string B, string C) {
	for (int i = 1; i <= A.size(); ++i) {
		char a = A[i - 1];
		for (int j = 1; j <= B.size(); ++j) {
			int b = B[j - 1];
			for (int k = 1; k <= C.size(); ++k) {
				char c = C[k - 1];
				F[i][j][k] = max({F[i][j][k - 1], F[i][j - 1][k], F[i - 1][j][k]});
				if (a == b && b == c)
					F[i][j][k] = max(F[i][j][k], F[i - 1][j - 1][k - 1] + 1);
			}
		}
	}
	return F[A.size()][B.size()][C.size()];
}

void Main() {
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		string a, b, c;
		cin >> a >> b >> c;
		cout << "Case " << i << ": " << Main(a, b, c) << endl;
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
