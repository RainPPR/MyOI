// Author: RainPPR
// Datetime: 2024-08-23 09:26

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

using ll = long long;

#define int ll

int n, A[N];

struct emm {
	int sum;
	int pre, suf;
	emm() = default;
	emm(int x): sum(x), pre(x), suf(x) {}
	friend emm operator +(const emm &a, const emm &b) {
		emm t;
		t.sum = a.sum + b.sum;
		t.pre = max(a.pre, a.sum + b.pre);
		t.suf = max(b.suf, b.sum + a.suf);
		return t;
	}
};

emm solve(int l, int r) {
	if (l == r)
		return emm(A[l]);
	int mid = (l + r) >> 1;
	auto L = solve(l, mid);
	auto R = solve(mid + 1, r);
	return L + R;
}

void Main() {
	cin >> n;
	copy_n(istream_iterator<int>(cin), n, A + 1);
	int Ans = max(A[1], A[n]);
	for (int i = 2; i < n; ++i) {
		int L = max(solve(1, i - 1).suf, 0ll);
		int R = max(solve(i + 1, n).pre, 0ll);
		Ans = max(Ans, A[i] + L + R);
	}
	cout << Ans << endl;
}

// -----------------------------------------------------------------------------

signed main() {
//	freopen("test_input.txt", "r", stdin);
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
