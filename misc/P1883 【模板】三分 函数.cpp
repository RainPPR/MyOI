// Author: RainPPR
// Datetime: 2024-08-14 18:36

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

mt19937 rnd(time(0));

template<typename T, typename CMP = less<T>>
using pqueue = __gnu_pbds::priority_queue<T, CMP>;
// using pqueue = priority_queue<T, vector<T>, CMP>;

// -----------------------------------------------------------------------------

constexpr double eps = 1e-9;

int n;

struct func_t {
	int a, b, c;
	func_t() = default;
	func_t(int a, int b, int c): a(a), b(b), c(c) {}
	double operator ()(const double &x) {
		return a * x * x + b * x + c;
	}
} func[10010];

double all_func(double x) {
	double res = func[1](x);
	for (int i = 2; i <= n; ++i)
		res = max(res, func[i](x));
	return res;
}

void Main(int _) {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> func[i].a >> func[i].b >> func[i].c;
	double l = 0, r = 1000;
	while (r - l >= eps) {
		double mid1 = l + (r - l) / 3;
		double mid2 = r - (r - l) / 3;
		if (all_func(mid1) > all_func(mid2))
			l = mid1;
		else
			r = mid2;
	}
	printf("%.4lf\n", all_func(l));
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