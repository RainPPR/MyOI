// Author: RainPPR
// Datetime: 2024-09-30 15:50

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

using ll = long long;

#define int ll

int n, x[N], y[N];

int sum[N], f[N][N * N];

int calc() {
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + x[i] + y[i];
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int k = 0; k <= sum[n]; ++k) {
			f[i][k] = 1e9;
			if (k >= x[i])
				f[i][k] = min(f[i][k], f[i - 1][k - x[i]] + x[i] * (k - x[i]) + y[i] * (sum[i] - k - y[i]));
			if (k >= y[i])
				f[i][k] = min(f[i][k], f[i - 1][k - y[i]] + y[i] * (k - y[i]) + x[i] * (sum[i] - k - x[i]));
		}
	int res = 1e9;
	for (int i = 1; i <= sum[n]; ++i)
		res = min(res, f[n][i]);
	return res;
}

void MaiN() {
	cin >> n;
	int pre = 0;
	for (int i = 1; i <= n; ++i)
		cin >> x[i], pre += x[i] * x[i];
	for (int i = 1; i <= n; ++i)
		cin >> y[i], pre += y[i] * y[i];
	cout << pre * (n - 1) + 2 * calc() << endl;
}

void Main() {
	int T;
	cin >> T;
	while (T--)
		MaiN();
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
