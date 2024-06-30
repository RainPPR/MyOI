#include <bits/stdc++.h>

using namespace std;

class odt_t {

private:

struct node_t {
    int l, r; mutable int v;
    node_t(int l): l(l) {} node_t(int l, int r, int v): l(l), r(r), v(v) {}
    friend bool operator <(const node_t &a, const node_t &b) { return a.l < b.l; }
};

set<node_t> odt;

auto split(int x) {
    auto it = --odt.upper_bound(node_t(x));
    if (it->l == x) return it;
    auto [l, r, v] = *it;
    odt.erase(it); odt.emplace(l, x - 1, v);
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
    res += (v - itl->v) * (itl->r - itl->l + 1);
    odt.erase(itb, itr), odt.emplace(l, r, v);
    return res;
}

void add(int l, int r, int v) {
    auto [itl, itr] = get(l, r);
    for (; itl != itr; ++itl) itl->v += v;
}

auto rank_k(int l, int r, int k) -> int {
    vector<pair<int, int>> bucket;
    auto [itl, itr] = get(l, r);
    for (; itl != itr; ++itl) bucket.push_back({itl->v, itl->r - itl->l + 1});
    sort(bucket.begin(), bucket.end());
    for (auto i : bucket) if ((k -= i.second) <= 0) return i.first;
    return -1;
}

void perform(int l, int r, auto f) {
    auto [itl, itr] = get(l, r);
    for (; itl != itr; ++itl) ; // do some thing
}

void debug() {
    for (auto [l, r, v] : odt)
    cerr << "(" << l << " " << r << ": " << v << ")";
    cerr << endl;
}

};
