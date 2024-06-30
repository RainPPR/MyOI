#pragma GCC optimize("Ofast,fast-math,-ffast-math")
#pragma GCC optimize("no-stack-protector,-funsafe-loop-optimizations")
#pragma GCC optimize("-fthread-jumps,unroll-loops,-funroll-loops")
#pragma GCC optimize("-falign-jumps,-falign-loops,-falign-labels,-falign-functions")
#pragma GCC optimize("-fexpensive-optimizations,-fdelete-null-pointer-checks")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

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
    int l, r; mutable int v;
    node_t(int l): l(l) {}
    node_t(int l, int r, int v): l(l), r(r), v(v) {}
    friend bool operator <(const node_t &a, const node_t &b) { return a.l < b.l; }
};

set<node_t> odt;

auto split(int x) {
    auto it = --odt.upper_bound(x);
    if (it->l == x) return it;
    auto [l, r, v] = *it;
    odt.erase(it), odt.emplace(l, x - 1, v);
    return odt.emplace(x, r, v).first;
}

auto get(int l, int r) {
    auto itr = split(r + 1), itl = split(l);
    return make_pair(itl, itr);
}

public:

void insert(int l, int r, int v) {
    odt.emplace(l, r, v);
}

void assign(int l, int r, int v) {
    auto [itl, itr] = get(l, r);
    odt.erase(itl, itr);
    odt.emplace(l, r, v);
}

int assign_result(int l, int r, int v) {
    auto [itl, itr] = get(l, r);
    auto itb = itl; int res = 0;
    for (; itl != itr; ++itl) if (itl->v != v)
    res -= itl->v * (itl->r - itl->l + 1),
    res += v * (itl->r - itl->l + 1);
    odt.erase(itb, itr);
    odt.emplace(l, r, v);
    return res;
}

int count(int l, int r) {
    auto [itl, itr] = get(l, r); int cnt = 0;
    for (; itl != itr; ++itl) if (itl->v) cnt += itl->r - itl->l + 1;
    return cnt;
}

};

signed main() {
    int n = rr, q = rr;
    odt_t odt; odt.insert(0, n, 0);
    int res = 0; while (q--) {
        int l = rr, r = rr, k = rr;
        res += odt.assign_result(l, r, 2 - k);
        printf("%d\n", n - res);
    } return 0;
}
