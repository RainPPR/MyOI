// Author: RainPPR
// Datetime: 2024-10-02 19:38

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

//using bi = basic_string<int>;

using ll = long long;

#define int ll

void calc(int n, int k) {
	if (n <= 62 && (k >> (n - 1)))
		return void(cout << -1 << endl);
	string bin = bitset<100>(k).to_string();
	reverse(bin.begin(), bin.end());
	bin.resize(n - 1);
//	cerr << "| " << n << " " << bin << endl;
	bin = bin + "0";
	vector<int> split;
	int tot = 0;
	for (char c : bin) {
		if (c == '1')
			++tot;
		else
			split.push_back(tot + 1), tot = 0;
	}
//	cerr << "| ";
//	for (int i : split)
//		cerr << i << " ";
//	cerr << endl;
	vector<int> ans(n);
	int pos = n - 1;
	for (auto it = split.begin(); it != split.end(); ++it) {
		int i = *it;
		int l = pos - i + 1, r = pos;
//		cerr << "| " << l << " " << r << " " << pos << " " << i << endl;
		for (int j = l; j <= r; ++j)
			ans[j] = pos--;
	}
	for (int i : ans)
		cout << i + 1 << " ";
	cout << endl;
}

void Main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		calc(n, k - 1);
	}
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
