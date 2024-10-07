// Author: RainPPR
// Datetime: 2024-10-01 09:33

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

#define gcd(x, y) __gcd(x, y)

constexpr int N = 2e5 + 10;

using ll = long long;

#define int ll

int n, a[N];
int st[20][N];

int get_gcd(int l, int r) {
	int k = __lg(r - l + 1);
	return gcd(st[k][l], st[k][r - (1 << k) + 1]);
}

bool check(int l, int r) {
	return get_gcd(l, r) > 1;
}

void MAIN() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		st[0][i] = abs(a[i + 1] - a[i]);
	--n;
	for (int k = 1; k < 20; ++k)
		for (int i = 1; i + (1 << k) - 1 <= n; ++i)
			st[k][i] = gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
	int ans = 0;
	for (int p = 1; p <= n; ++p) {
		int l = p, r = n;
		int q = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(p, mid))
				q = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		ans = max(ans, q - p + 1);
	}
	cout << ans + 1 << endl;
}

void Main() {
	int T;
	cin >> T;
	while (T--)
		MAIN();
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
