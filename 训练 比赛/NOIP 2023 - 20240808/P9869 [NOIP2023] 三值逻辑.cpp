// Author: RainPPR
// Datetime: 2024-10-03 14:36

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

constexpr int N = 1e5 + 10;

int n, m;

struct edge {
	int v, w;
	edge() = default;
	edge(int v, int w): v(v), w(w) {}
};

vector<edge> G[N];

int fa[N], ac[N];
int ROOT_T, ROOT_U;

int vis[N], col[N];

int get_size(int u, int *flag) {
	if (flag == nullptr) {
		flag = new int;
		*flag = 1;
	}
	vis[u] = 1;
	int siz = 1;
	for (auto t : G[u]) {
		int v = t.v, w = t.w;
		if (!vis[v]) {
			col[v] = col[u] ^ w;
			siz += get_size(v, flag);
		}
		else if (col[v] != (col[u] ^ w))
			*flag = 0;
	}
//	cerr << "| " << u << ": " << siz << endl;
	return siz;
}

int calc() {
	cin >> n >> m;

	ROOT_T = n + 1, ROOT_U = n + 2;
	for (int i = 1; i <= n + 2; ++i)
		fa[i] = i, ac[i] = 0, G[i].clear();

	char c;
	int x, y;

	while (m--) {
		cin >> c >> x;
		if (c == 'T')
			fa[x] = ROOT_T, ac[x] = 0;
		else if (c == 'F')
			fa[x] = ROOT_T, ac[x] = 1;
		else if (c == 'U')
			fa[x] = ROOT_U, ac[x] = 0;
		else {
			cin >> y;
			if (c == '+')
				fa[x] = fa[y], ac[x] = ac[y];
			else if (c == '-')
				fa[x] = fa[y], ac[x] = ac[y] ^ 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		G[i].emplace_back(fa[i], ac[i]);
		G[fa[i]].emplace_back(i, ac[i]);
//		cerr << "| EDGE {" << i << ", " << fa[i] << ", " << ac[i] << "}" << endl;
	}

	memset(vis, 0, sizeof vis);
	int ans = get_size(ROOT_U, nullptr) - 1;

	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; ++i) {
		if (vis[i])
			continue;
		col[i] = 0;
		int flag = 1;
		int res = get_size(i, &flag);
		if (!flag)
			ans += res;
	}
	return ans;
}

void Main() {
	int c, t;
	cin >> c >> t;
	while (t--)
		cout << calc() << endl;
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
