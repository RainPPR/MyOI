// Author: RainPPR
// Datetime: 2024-09-30 22:01

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

void m_sort(int *arr, int n) {
	static int cnt[N];
	memset(cnt, 0, sizeof cnt);
	int minn = 1e9, maxn = 0;
	for (int i = 1; i <= n; ++i) {
		++cnt[arr[i]];
		minn = min(minn, arr[i]);
		maxn = max(maxn, arr[i]);
	}
	for (int i = minn, j = 0; i <= maxn; ++i)
		for (int k = 0; k < cnt[i]; ++k)
			arr[++j] = i;
}

int n, k;
int a[N], sorted[N];

void MAIN() {
	cin >> n >> k;
	int len = (n + k + 1) >> 1;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], sorted[i] = a[i];
	m_sort(sorted, n);
	int l = 0, r = 1e9;
	for (int i = len; i <= n; ++i)
		if (sorted[i] - sorted[i - len + 1] < r - l)
			l = sorted[i - len + 1], r = sorted[i];
	cout << l << " " << r << endl;
	int cnt = 0, tot = 0, last = 1;
	for (int i = 1; i <= n; ++i) {
		cnt += (a[i] >= l && a[i] <= r) ? 1 : -1;
		if (cnt > 0 && tot < k - 1) {
			++tot;
			cout << last << " " << i << endl;
			last = i + 1, cnt = 0;
		}
	}
	cout << last << " " << n << endl;
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
