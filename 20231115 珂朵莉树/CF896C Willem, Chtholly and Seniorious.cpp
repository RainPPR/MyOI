#include <bits/stdc++.h>

using namespace std;

using ll = long long;

inline ll qpow(ll a, ll b, ll p) {
    a %= p; ll r = 1;
    for (; b; b >>= 1) {
        if (b & 1) r = r * a % p;
        a = a * a % p;
    } return r;
}

class odt_t {

private:

struct node {
    int l, r; mutable ll v;
    node(int l) : l(l), r(0), v(0) {}
    node(int l, int r, ll v) : l(l), r(r), v(v) {}
    friend bool operator <(const node &a, const node &b) { return a.l < b.l; }
}; set<node> odt;

auto split(int x) {
    auto it = prev(odt.upper_bound(node(x)));
    if (it->l == x) return it;
    int l = it->l, r = it->r; ll v = it->v;
    odt.erase(it); odt.emplace(l, x - 1, v);
    return odt.emplace(x, r, v).first;
}

public:

void insert(int l, int r, ll v) {
    odt.emplace(l, r, v);
}

void assign(int l, int r, ll v) {
    auto itr = split(r + 1), itl = split(l);
    odt.erase(itl, itr), odt.emplace(l, r, v);
}

void performance(int l, int r, auto op) {
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) op(itl);
}

void add(int l, int r, ll v) {
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) itl->v += v;
}

auto rank_k(int l, int r, int k) -> ll {
    vector<pair<ll, int>> bucket;
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) bucket.push_back({itl->v, itl->r - itl->l + 1});
    sort(bucket.begin(), bucket.end());
    for (auto i : bucket)
    if ((k -= i.second) <= 0) return i.first;
    return -1;
}

auto range_power(int l, int r, ll pw, ll md) -> ll {
    ll q = 0; auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl)
    q = (q + 1ll * (itl->r - itl->l + 1) * qpow(itl->v, pw, md) % md) % md;
    return q;
}

};

constexpr int mod = 1e9 + 7;

signed main() {
    int n, m, seed, vmax; scanf("%d%d%d%d", &n, &m, &seed, &vmax);
    auto rnd = [&] () { int ret = seed; return (seed = (seed * 7ll + 13) % mod, ret); };
    odt_t odt; for (int i = 1; i <= n; ++i) odt.insert(i, i, rnd() % vmax + 1);
    auto doi = [&] (int op, int l, int r, int x, int y) {
        switch (op) {
            case 1: odt.add(l, r, x); break;
            case 2: odt.assign(l, r, x); break;
            case 3: printf("%lld\n", odt.rank_k(l, r, x)); break;
            case 4: printf("%lld\n", odt.range_power(l, r, x, y)); break;
            default: throw("UNKNOWN OPERATOR");
        } return (void)("rp++");
    }; for (int i = 1; i <= m; ++i) {
        int op = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
        ll x, y; if (l > r) swap(l, r);
        if (op == 3) x = rnd() % (r - l + 1) + 1;
        else x = rnd() % vmax + 1;
        if (op == 4) y = rnd() % vmax + 1;
        doi(op, l, r, x, y);
    } return 0;
}
