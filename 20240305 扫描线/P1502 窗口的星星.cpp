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
    int x1, x2, y, v;
    line() = default;
    line(int a, int b, int y, int v): x1(a), x2(b), y(y), v(v) {}
    friend bool operator <(const line &a, const line &b) { return a.y < b.y; }
};

namespace seg {
    #define ls(k) ((k) << 1)
    #define rs(k) ((k) << 1 | 1)

    vector<int> q;

    struct node {
        int l, r;
        ll v, add;
    } a[N << 2];

    void push_up(int k) {
        a[k].v = max(a[ls(k)].v, a[rs(k)].v);
    }

    void action(int k, int v) {
        a[k].v += v;
        a[k].add += v;
    }

    void push_down(int k) {
        ;
    }

    void build(int k, int l, int r) {
        a[k] = {q[l], q[r], 0};
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(ls(k), l, mid);
        build(rs(k), mid + 1, r);
    }

    void modify(int k, int p, int q, int v) {
        ;
    }

    void init(const auto &s, int n) {
        q = s;
        build(1, 1, n);
    }

    void change(int a, int b, int c) {
        modify(1, a, b, c);
    }

    void calc() {
        return a[1].v;
    }
}

ll Main() {
    vector<line> q;
    vector<int> s;
    for (int i = 1; i <= n; ++i) {
        int x, y, l;
        cin >> x >> y >> l;
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = make_tuple(x, y, x + W - 1, y + H - 1);
        s.push_back(x1);
        s.push_back(x2);
        q.emplace_back(x1, x2, y1, l);
        q.emplace_back(x1, x2, y2, -l);
    }
    sort(q.begin(), q.end());
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    seg::init(s, (int)s.size());
    ll ans = 0;
    for (int i = 0; i + 1 < (int)q.size(); ++i) {
        seg::change(q[i].x1, q[i].x2, q[i].v);
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