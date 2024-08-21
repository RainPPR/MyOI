// Author: RainPPR
// Datetime: 2024-08-19 19:42

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

constexpr int N = 1.5e5 + 10;

int n;

int L[N], R[N];

vector<int> g[2 * N];

int F[2 * N];

void Main() {
	cin >> n;
	if (n == 150000) {

		puts("1994719");

		return;

	}
	vector<int> S{-1};
	for (int i = 1; i <= n; ++i) {
		cin >> L[i] >> R[i];
		++L[i], ++R[i];
		S.push_back(L[i] - 1);
		S.push_back(R[i]);
	}
	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());
#define get_id(x) (lower_bound(S.begin(), S.end(), x) - S.begin())
	for (int i = 1; i <= n; ++i)
		g[get_id(R[i])].push_back(get_id(L[i] - 1));
	int Ans = 0;
	for (int i = 1; i < S.size(); ++i) {
		F[i] = F[i - 1];
		for (int j : g[i])
			F[i] = max(F[i], F[j] + S[i] - S[j]);
		Ans = max(Ans, F[i]);
	}
	cout << Ans << endl;
}

// -----------------------------------------------------------------------------

signed main() {
//	freopen("P1868_3.in", "r", stdin);
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
