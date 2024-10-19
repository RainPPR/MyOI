// Author: RainPPR
// Datetime: 2024-08-31 14:10

#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1

#define D(x) ({ void(0); })
#else
#define D(x) ({ auto __ = (x); cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << __ << "]\n"; void(0); })
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

constexpr int N = 1010;
constexpr int MOD = 998244353;

int n, m, t;

vector<int> G[N];

int in[N], out[N];

int val[N], tmp[N];

void show(string deb) {
	cerr << deb << ": ";
	for (int i = 1; i <= n; ++i)
		cerr << val[i] << " ";
	cerr << endl;
}

void show(int x) {
	show(to_string(x));
}

int brute() {
	for (int d = 1; d <= n; ++d) {
		bool flag = false;
		bool exist = false;
		for (int i = 1; i <= n; ++i)
			if (val[i]) {
				--val[i];
				exist = true;
				for (int j : G[i])
					++tmp[j];
				flag |= val[i] > 0;
			}
		if (!exist)
			return d - 1;
		for (int i = 1; i <= n; ++i)
			if (tmp[i]) {
				val[i] += tmp[i];
				tmp[i] = 0;
				flag |= val[i] > 0;
			}
		if (!flag)
			return d;
	}
	return -1;
}

queue<int> q;

int top() {
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : G[u]) {
			val[v] = (val[v] + val[u]) % MOD;
			--in[v];
			if (in[v] == 0)
				q.push(v);
		}
	}
	return val[t];
}

void Main(int _) {
	_ = _;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		in[i] = out[i] = 0;
		G[i].clear();
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		++out[u], ++in[v];
	}
	for (int i = 1; i <= n; ++i)
		if (out[i] == 0)
			t = i;
	int res = brute();
	if (res == -1) {
		for (int i = 1; i <= n; ++i)
			if (in[i] == 0)
				q.push(i);
		res = (top() + n) % MOD;
	}
	cout << res << endl;
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
