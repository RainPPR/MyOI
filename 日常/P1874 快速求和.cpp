// Author: RainPPR
// Datetime: 2024-08-20 21:22

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

constexpr int MOD = 998244353;

int n, tar;

string str;

int R[50], S[50];

void init() {
	R[0] = 1, S[0] = 0;
	for (int i = 1; i <= n; ++i) {
		R[i] = R[i - 1] * 10ll % MOD;
		S[i] = (S[i - 1] * 10ll % MOD + str[i - 1] - '0') % MOD;
	}
}

int get(int l, int r) {
	return (S[r] - 1ll * S[l - 1] * R[r - l + 1] % MOD + MOD) % MOD;
}

unordered_set<int> F[50][50];

void Main() {
	cin >> str >> tar;
	n = str.size();
	init();
	for (int i = 1; i <= n; ++i) {
		if (i <= 7)
			F[i][0].insert(get(1, i));
		for (int k = 1; k < i; ++k)
			for (int j = max(2, i - 6); j <= i; ++j)
				for (int t : F[j - 1][k - 1])
					//	if (t + get(j, i) <= tar)
					F[i][k].insert(t + get(j, i));
	}
	int Ans = 1e9;
	for (int k = 0; k < n; ++k)
		for (int t : F[n][k])
			if (t == tar) {
				Ans = k;
				break;
			}
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
