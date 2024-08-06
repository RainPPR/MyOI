#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1
#define D(x) ({ void(0); })
#else
#define D(x) ({ auto t = (x); cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << t << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

// -----------------------------------------------------------------------------

constexpr int N = 1e5 + 10;

int n, W, H;

using ll = long long;

struct line {
    ll x1, x2, y, v;
    line() = default;
    line(ll a, ll b, ll y, ll v): x1(a), x2(b), y(y), v(v) {}
    friend bool operator <(const line &a, const line &b) {
        if (a.y == b.y) return a.v > b.v;
        return a.y < b.y;
    }
};

namespace seg {
    #define ls(k) ((k) << 1)
    #define rs(k) ((k) << 1 | 1)

    struct node {
        ll l, r;
        ll v, add;
    } a[N << 3];

    void action(int k, ll v) {
        a[k].v += v;
        a[k].add += v;
    }

    void push_up(int k) {
        a[k].v = max(a[ls(k)].v, a[rs(k)].v);
    }

    void build(int k, ll l, ll r) {
        a[k] = {l, r, 0, 0};
        if (l == r) return;
        ll mid = l + ((r - l) >> 1);
        build(ls(k), l, mid);
        build(rs(k), mid + 1, r);
    }

    void push_down(int k) {
        if (a[k].add == 0) return;
        action(ls(k), a[k].add);
        action(rs(k), a[k].add);
        a[k].add = 0;
    }

    void modify(int k, ll p, ll q, ll v) {
        ll l = a[k].l, r = a[k].r;
        if (l >= p && r <= q) return action(k, v);
        push_down(k);
        ll mid = l + ((r - l) >> 1);
        if (mid >= p) modify(ls(k), p, q, v);
        if (mid + 1 <= q) modify(rs(k), p, q, v);
        push_up(k);
    }

    void init(int n) {
        build(1, 1, n);
    }

    void change(ll a, ll b, ll c) {
        modify(1, a, b, c);
    }

    ll calc() {
        return a[1].v;
    }
}

ll Main() {
    vector<line> q;
    vector<int> s;
    for (int i = 1; i <= n; ++i) {
        ll x1, y1, l;
        cin >> x1 >> y1 >> l;
        ll x2 = x1 + W - 1;
        ll y2 = y1 + H - 1;
        s.push_back(x1);
        s.push_back(x2);
        q.emplace_back(x1, x2, y1, l);
        q.emplace_back(x1, x2, y2, -l);
    }
    sort(q.begin(), q.end());
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    #define get_id(x) (lower_bound(s.begin(), s.end(), x) - s.begin() + 1)
    seg::init((int)s.size());
    ll ans = 0;
    for (int i = 0; i + 1 < (int)q.size(); ++i) {
        seg::change(get_id(q[i].x1), get_id(q[i].x2), q[i].v);
        ans = max(ans, seg::calc());
    }
    return ans;
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    #if ONLINE_JUDGE==luogu
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> W >> H;
        cout << Main() << endl;
    }
    #else
    while (cin >> n >> W >> H)
        cout << Main() << endl;
    #endif
    return 0;
}