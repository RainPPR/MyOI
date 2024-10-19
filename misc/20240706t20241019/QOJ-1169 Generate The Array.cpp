// Author: RainPPR
// Datetime: 2024-08-28 20:16

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

constexpr int M = 3e5 + 10;
constexpr int N = 300 + 10;

using ll = long long;

#define int ll

// using i128 = __int128;

int n, Q[N][N], F[N][N];

int sum(int a, int b, int c, int d) {
	return Q[b][d] - Q[a - 1][d] - Q[b][c - 1] + Q[a - 1][c - 1];
}

struct line {
	int k, b;
} p[M];

int tot;

int calc(int u, int t) {
	return p[u].k * t + p[u].b;
}

struct node {
	node *ls, *rs;
	int best;
	node(): ls(nullptr), rs(nullptr) {}
	node(int u): ls(nullptr), rs(nullptr), best(u) {}
} *root[N];

void modify(node *&k, int l, int r, int u) {
	if (k == nullptr)
		k = new node(u);
	int mid = (l + r) >> 1;
	int &v = k->best;
	if (calc(u, mid) > calc(v, mid))
		swap(u, v);
	if (calc(u, l) > calc(v, l))
		modify(k->ls, l, mid, u);
	if (calc(u, r) > calc(v, r))
		modify(k->rs, mid + 1, r, u);
}

int query(node *k, int l, int r, int t) {
	if (k == nullptr)
		return -1e18;
	int res = calc(k->best, t);
	if (l == r)
		return res;
	int mid = (l + r) >> 1;
	if (t <= mid)
		res = max(res, query(k->ls, l, mid, t));
	else
		res = max(res, query(k->rs, mid + 1, r, t));
	return res;
}

void Insert(int u, int k, int b) {
	p[++tot] = line{k, b};
	modify(root[u], 0, Q[n][n], tot);
}

int Query(int u, int t) {
	int kk = query(root[u], 0, Q[n][n], t);
	return kk;
}

void Main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			cin >> Q[i][j], F[i][j] = -1e18;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			Q[i][j] += Q[i - 1][j] + Q[i][j - 1] - Q[i - 1][j - 1];
	for (int i = 1; i <= n; ++i)
		root[i] = nullptr;
	for (int i = 1, k, v, c; i <= n; ++i)
		for (cin >> k; k--;)
			cin >> v >> c, Insert(i, v, -c);
	for (int len = 1; len <= n; ++len)
		for (int l = 1, r = len; r <= n; ++l, ++r)
			for (int k = l; k <= r; ++k)
				F[l][r] = max(F[l][r], F[l][k - 1] + F[k + 1][r] + Query(k, sum(l, k, k, r)));
	cout << F[1][n] << endl;
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
