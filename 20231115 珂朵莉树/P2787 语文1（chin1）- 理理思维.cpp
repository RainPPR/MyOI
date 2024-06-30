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

int count(int l, int r, int v) {
    auto [itl, itr] = get(l, r);
    int res = 0;
    for (; itl != itr; ++itl) if (itl->v == v) res += itl->r - itl->l + 1;
    return res;
}

void partial_sort(int l, int r) {
    auto [itl, itr] = get(l, r); auto bkl = itl;
    array<int, 26> app; app.fill(0);
    for (; itl != itr; ++itl) app[itl->v] += itl->r - itl->l + 1;
    odt.erase(bkl, itr);
    for (int i = 0, now = l; i < 26; ++i) if (app[i])
    odt.emplace(now, now + app[i] - 1, i), now += app[i];
}

void debug() {
    for (auto i : odt) cerr << "(" << i.l << " " << i.r << ": " << (char)(i.v+'A') << ")";
    cerr << endl;
}

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    odt_t odt;
    rep(i, n) odt.insert(i + 1, i + 1, tolower(s[i]) - 'a');
    odt.insert(n + 1, n + 1, 0);
    while (m--) {
        int op, x, y; cin >> op >> x >> y;
        if (op == 3) odt.partial_sort(x, y);
        else {
            char e; cin >> e; int k = tolower(e) - 'a';
            if (op == 1) cout << odt.count(x, y, k) << endl;
            else odt.assign(x, y, k);
        }
    }
    return 0;
}
