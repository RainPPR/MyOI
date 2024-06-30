#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define getchar() getchar_unlocked()
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
}

void assign(ll l, ll r, int v) {
    auto [itl, itr] = get(l, r);
    odt.erase(itl, itr);
    odt.emplace(l, r, v);
}

ll count(ll l, ll r) {
    auto [itl, itr] = get(l, r); ll cnt = 0;
    for (; itl != itr; ++itl) if (itl->v) cnt += itl->r - itl->l + 1;
    return cnt;
}

};

ll solve(vector<pll> node) {
    odt_t odt; odt.insert(0, 1e17, 0);
    for (auto &[l, r] : node) odt.assign(l, r, 1);
    return odt.count(0, 1e17);
}

signed main() {
    int n = rr; vector<pll> node(n);
    for (auto &[l, r] : node) l = rl, r = rl;
    printf("%lld\n", solve(node));
    return 0;
}
