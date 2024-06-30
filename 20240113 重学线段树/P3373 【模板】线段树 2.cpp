#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read<int>()
#define ur uread<int>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = n * 10 + c - '0';
    return f ? -n : n;
}

template<typename tp>
inline tp uread() {
    tp n = 0; int c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

constexpr int root = 1;

int mod;

class seg_t {

private:

struct emm {
    int l, r;
    ll v, ad, ml;
};

int n; vector<emm> a;

void push_up(int k) {
    (a[k].v = a[k * 2].v + a[k * 2 + 1].v) %= mod;
}

void action_add(int k, ll t) {
    (a[k].ad += t) %= mod;
    (a[k].v += t * (a[k].r - a[k].l + 1) % mod) %= mod;
}

void action_mul(int k, ll t) {
    (a[k].v *= t) %= mod;
    (a[k].ad *= t) %= mod, (a[k].ml *= t) %= mod;
}

void push_down(int k) {
    if (a[k].ml != 1) {
        action_mul(k * 2, a[k].ml);
        action_mul(k * 2 + 1, a[k].ml);
        a[k].ml = 1;
    } if (a[k].ad) {
        action_add(k * 2, a[k].ad);
        action_add(k * 2 + 1, a[k].ad);
        a[k].ad = 0;
    }
}

void build(vector<ll> &q, int k, int l, int r) {
    a[k].l = l, a[k].r = r; a[k].ad = 0, a[k].ml = 1;
    if (l == r) { a[k].v = q[l]; return; }
    int mid = l + (r - l >> 1);
    build(q, k * 2, l, mid);
    build(q, k * 2 + 1, mid + 1, r);
    push_up(k);
}

ll query(int k, int p, int q) {
    auto &l = a[k].l, &r = a[k].r;
    if (l >= p && r <= q) return a[k].v;
    push_down(k); int mid = l + (r - l >> 1);
    ll res = 0;
    if (mid >= p) res += query(k * 2, p, q);
    if (mid + 1 <= q) res += query(k * 2 + 1, p, q);
    return res % mod;
}

void modify_add(int k, int p, int q, ll v) {
    auto &l = a[k].l, &r = a[k].r;
    if (l >= p && r <= q) { action_add(k, v); return; }
    push_down(k); int mid = l + (r - l >> 1);
    if (mid >= p) modify_add(k * 2, p, q, v);
    if (mid + 1 <= q) modify_add(k * 2 + 1, p, q, v);
    push_up(k);
}

void modify_mul(int k, int p, int q, ll v) {
    auto &l = a[k].l, &r = a[k].r;
    if (l >= p && r <= q) { action_mul(k, v); return; }
    push_down(k); int mid = l + (r - l >> 1);
    if (mid >= p) modify_mul(k * 2, p, q, v);
    if (mid + 1 <= q) modify_mul(k * 2 + 1, p, q, v);
    push_up(k);
}

public:

seg_t(vector<ll> &q) { n = q.size(); a.resize(n * 4); build(q, root, 1, n); }
ll sum(int l, int r) { return query(root, l, r); }
void add(int l, int r, ll v) { modify_add(root, l, r, v); }
void mul(int l, int r, ll v) { modify_mul(root, l, r, v); }

};

signed main() {
    int n = ur, q = ur; mod = ur;
    vector<ll> a(n + 1);
    rep(i, n) a[i + 1] = ur;
    seg_t seg(a);
    while (q--) {
        int op = ur, x = ur, y = ur;
        if (op == 3) printf("%lld\n", seg.sum(x, y));
        else if (op == 1) seg.mul(x, y, ur);
        else if (op == 2) seg.add(x, y, ur);
    } return 0;
}