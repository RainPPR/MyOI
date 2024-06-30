#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define endl '\n'

class odt_t {

private:

struct node_t {
    int l, r; mutable int v;
    node_t(int l): l(l), r(0), v(0) {}
    node_t(int l, int r, int v): l(l), r(r), v(v) {}
    friend bool operator <(const node_t &a, const node_t &b) { return a.l < b.l; }
};

set<node_t> odt;

auto split(int x) {
    auto it = prev(odt.upper_bound(node_t(x)));
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
    insert(l, r, v);
}

bool check(int l, int r) {
    auto [itl, itr] = get(l, r);
    int v = itl->v;
    if (itl != odt.begin() && itr != odt.end() && prev(itl)->v == itr->v) return false;
    for (int farv = l; ++itl != itr; farv = itl->r)
        if (itl->v != v) return (assign(l, farv, v), false);
    return (assign(l, r, v), true);
}

void debug() {
    for (auto i : odt) cerr << "(" << i.l << " " << i.r << ": " << i.v << ")";
    cerr << endl;
}

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    odt_t odt; odt.insert(n + 1, n + 1, -1);
    rep(i, n) odt.insert(i + 1, i + 1, s[i] - 'A');
    int k; cin >> k;
    while (k--) {
        string op; int x, y;
        cin >> op >> x >> y;
        if (op[0] == 'B') cout << (odt.check(x, y) ? "Yes" : "No") << endl;
        else { string v; cin >> v; odt.assign(x, y, v[0] - 'A'); }
    } return 0;
}
