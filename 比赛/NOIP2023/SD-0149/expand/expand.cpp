// rp++ what do your do at the end of the world?
// Y@2L32#
// T#YMS@4
// node: 0+998244710

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#ifdef __unix
#define getchar() getchar_unlocked()
#endif

#define endl '\n'
#define rr read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = getchar();
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

#define open(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(nullptr), cout.tie(nullptr)

template<typename tp> inline tp Max(const tp a, const tp b) { return a > b ? a : b; }
template<typename tp> inline tp Min(const tp a, const tp b) { return a < b ? a : b; }
template<typename tp> inline tp Abs(const tp a) { return a < 0 ? -a : a; }

#define chmin(a, x) ((a) = Min(a, x))
#define chmax(a, x) ((a) = Max(a, x))

signed main() {
    open("expand");
    int c = rr, n = rr, m = rr, q = rr;
    rep(i, q + 1) putchar('1');
    cout << endl;
    return 0;
}
