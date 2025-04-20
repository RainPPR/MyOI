#include <bits/stdc++.h>

using namespace std;

using ll = long long;

inline ll getAlign(ll pool, int Align) {
    return ceil(pool * 1.0 / Align) * Align;
}

struct Var {
    string type, name; ll addr;
};

struct Type {
    vector<Var> Member;
    map<ll, string> addr;
    unordered_map<string, int> oPs;
    ll Size, Align;
    Type() = default;
    Type(ll def): Size(def), Align(def) {}
    Type(ll size, ll align): Size(size), Align(align) {}
};

unordered_map<string, Type> getType = {
    {"byte",  Type(1)},
    {"short", Type(2)},
    {"int",   Type(4)},
    {"long",  Type(8)}
};

ll Pool = 0;

map<ll, string> op4;
unordered_map<string, pair<string, ll>> op3;

void insertType() {
    string name; int k; Type type;
    cin >> name >> k; type.Member.resize(k);
    ll pool = 0, align = -1;
    string tp, nm; for (int i = 0; i < k; ++i) {
        cin >> tp >> nm; ll s = getType[tp].Align;
        pool = getAlign(pool, s), align = max(align, s);
        type.oPs[nm] = i; type.addr[pool] = nm;
        type.Member[i].type = tp, type.Member[i].name = nm;
        type.Member[i].addr = pool, pool += getType[tp].Size;
    } pool = getAlign(pool, align);
    type.Size = pool, type.Align = align;
    cout << pool << " " << align << endl;
    return void(getType[name] = type);
}

void insertVar() {
    string type, name; cin >> type >> name;
    ll beg = getType[type].Align;
    Pool = getAlign(Pool, beg); cout << Pool << endl;
    op3[name] = {type, Pool}, op4[Pool] = name;
    Pool += getType[type].Size;
}

void getAddr() {
    string vr; cin >> vr; vr = vr + ".";
    vector<string> opq; string base;
    for (char c : vr) if (c != '.') base.push_back(c);
    else opq.push_back(base), base = "";
    string now = op3[opq[0]].first; ll addr = op3[opq[0]].second;
    for (int i = 1; i < opq.size(); ++i) {
        string name = opq[i];
        addr += getType[now].Member[getType[now].oPs[name]].addr;
        now = getType[now].Member[getType[now].oPs[name]].type;
    } cout << addr << endl;
}

void getName() {
    ll addr; cin >> addr;
    auto it1 = op4.upper_bound(addr);
    if (it1 == op4.begin()) return void(cout << "ERR" << endl);
    string ans = (--it1)->second;
    string now = op3[ans].first;
    addr -= it1->first; while (1) {
        auto t = getType[now];
        if (t.addr.size() == 0) break;
        auto it2 = t.addr.upper_bound(addr);
        if (it2 == t.addr.begin()) return void(cout << "ERR" << endl);
        ans += "." + (--it2)->second, addr -= it2->first;
        now = t.Member[t.oPs[it2->second]].type;
    } if (addr >= getType[now].Size) cout << "ERR" << endl;
    else cout << ans << endl;
}

void action(int op) {
    if (op == 1) insertType(); if (op == 2) insertVar();
    if (op == 3) getAddr();    if (op == 4) getName();
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
    int n, op; cin >> n; while (n--) cin >> op, action(op);
    return 0;
}
