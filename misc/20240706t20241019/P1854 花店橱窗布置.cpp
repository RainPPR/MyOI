// Author: RainPPR
// Datetime: 2024-08-22 10:37

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

int n, m;

int A[N][N];
int F[N][N], G[N][N];

void Main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> A[i][j];
	memset(F, -0x3f, sizeof F);
	F[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int k = 0; k < j; ++k)
				if (F[i - 1][k] + A[i][j] > F[i][j])
					F[i][j] = F[i - 1][k] + A[i][j], G[i][j] = k;
	int Ans = -1e9, Pos = 0;
	for (int i = 1; i <= m; ++i)
		if (F[n][i] > Ans)
			Ans = F[n][i], Pos = i;
	cout << Ans << endl;
	vector<int> Res;
	for (int i = n; i >= 1; --i) {
		Res.push_back(Pos);
		Pos = G[i][Pos];
	}
	for (auto it = Res.rbegin(); it != Res.rend(); ++it)
		cout << *it << " ";
	cout << endl;
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
