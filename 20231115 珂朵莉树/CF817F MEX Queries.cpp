#pragma GCC optimize("Ofast,fast-math,inline")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

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
    #pragma GCC unroll 8
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    #pragma GCC unroll 8
    for (; isdigit(c); c = getchar()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

template<typename tp> inline tp Max(tp a, tp b) { return a > b ? a : b; }
template<typename tp> inline tp Min(tp a, tp b) { return a > b ? a : b; }

class odt_t {

private:

struct node_t {
    ll l, r; mutable int v;
    node_t(ll l): l(l) {}
    node_t(ll l, ll r, int v): l(l), r(r), v(v) {}
    friend bool operator <(const node_t &a, const node_t &b) { return a.l < b.l; }
};

set<node_t> odt;

auto split(ll x) {
    auto it = --odt.upper_bound(x);
    if (it->l == x) return it;
    auto [l, r, v] = *it;
    odt.erase(it), odt.emplace(l, x - 1, v);
    return odt.emplace(x, r, v).first;
}

auto get(ll l, ll r) {
    auto itr = split(r + 1), itl = split(l);
    return make_pair(itl, itr);
}

public:

void insert(ll l, ll r, int v) {
    odt.emplace(l, r, v);
    return (void)("what do you do at the end of the world?");
}

void assign(ll l, ll r, int v) {
    auto [itl, itr] = get(l, r);
    odt.erase(itl, itr);
    odt.emplace(l, r, v);
    return (void)("are you basy?");
}

void cpl(ll l, ll r) {
    auto [itl, itr] = get(l, r);
    #pragma GCC unroll 8
    for (; itl != itr; ++itl) itl->v ^= 1;
    return (void)("will you save us?");
}

ll getmex(ll l, ll r) {
    auto [itl, itr] = get(l, r);
    #pragma GCC unroll 8
    for (; itl != itr; ++itl)
    if (!itl->v) return itl->l;
    return (ll)(1e18) + 1;
}

};

signed main() {
    int n = rr; odt_t odt;
    odt.insert(0, 1e18, 0);
    odt.insert(1e18 + 1, 1e18 + 1, 1);
    while (n--) {
        int t = rr; ll l = rl, r = rl;
        if (t == 1) odt.assign(l, r, 1);
        else if (t == 2) odt.assign(l, r, 0);
        else odt.cpl(l, r);
        printf("%lld\n", odt.getmex(1, 1e18 + 1));
    } return 0;
}
