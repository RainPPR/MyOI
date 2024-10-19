// Author: RainPPR
// Datetime: 2024-09-30 10:13

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

constexpr int N = 1e6 + 10;

int n, c, a[N];

int cnt[N], sum[N];

bool check() {
	if (!cnt[1])
		return false;
	for (int i = 1; i <= c; ++i)
		sum[i] = sum[i - 1] + cnt[i];
	for (int k = 2; k <= c; ++k) {
		if (!cnt[k])
			continue;
		for (int a = k; a <= c; a += k)
			if (sum[min(c, a + k - 1)] - sum[a - 1] && !cnt[a / k])
				return false;
	}
	return true;
}

void Main(int _) {
	_ = _;
	cin >> n >> c;
	memset(cnt, 0, sizeof(int) * (c + 1));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]] = 1;
	}
	puts(check() ? "Yes" : "No");
}

void Main() {
	int T;
	cin >> T;
	while (T--)
		Main(T);
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
