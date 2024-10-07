// Author: RainPPR
// Datetime: 2024-10-03 17:51

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

using ll = long long;
using lll = __int128;

#define int ll

#define abs(x) ((x) < 0 ? -(x) : (x))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

constexpr int N = 1e5 + 10;

int n;
int a[N], b[N], c[N];

vector<int> G[N];

int fa[N];

void dfs(int u, int ff) {
	fa[u] = ff;
	for (int v : G[u])
		if (v != ff)
			dfs(v, u);
}

lll G1(lll x, int l, int r) {
	return b[x] * (r - l + 1) + c[x] * (((lll)(l + r) * (r - l + 1)) >> 1);
}

lll calc(int x, int l, int r) {
	if (c[x] >= 0)
		return G1(x, l, r);
	lll imax = (1 - b[x]) / c[x];
	if (imax < l)
		return r - l + 1;
	if (imax > r)
		return G1(x, l, r);
	return G1(x, l, imax) + r - imax;
}

int get_lim(int i, int m) {
	int l = 1, r = m;
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (calc(i, mid, m) >= a[i])
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	return ans;
}

int lim[N], id[N], vis[N];

bool check(int r) {
	for (int i = 1; i <= n; ++i) {
		int x = get_lim(i, r);
		if (i != 1 && x == 1)
			return false;
		lim[i] = x;
		id[i] = i;
		vis[i] = false;
		if (x == -1)
			return false;
	}
	sort(id + 1, id + n + 1, [] (int a, int b) {
		return lim[a] < lim[b];
	});
	int x = 0;
	stack<int> stk;
	for (int t = 1; t <= n; ++t) {
		int i = id[t];
		while (i && !vis[i]) {
			stk.push(i);
			vis[i] = true;
			i = fa[i];
		}
		while (!stk.empty()) {
			int u = stk.top();
			stk.pop();
			if (++x > lim[u])
				return false;
		}
	}
	return true;
}

void Main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	int l = 1, r = 1e9;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	cout << (long long)ans << endl;
}

// -----------------------------------------------------------------------------

signed main() {
//	freopen("tree3.in", "r", stdin);
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
