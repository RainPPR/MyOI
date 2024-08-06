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

struct query {
    double x1, x2, y;
    int v;
    query() = default;
    query(double a, double b, double c, int v): x1(a), x2(b), y(c), v(v) {}
    friend bool operator <(const query &a, const query &b) {
        return a.y < b.y;
    }
};

template<typename T>
void owap(T &a, T &b) {
    if (a > b) swap(a, b);
}

namespace seg {
    int n;
    vector<double> q;

    struct node {
        double l, r, len;
        int cnt;
    } a[N << 2];

    void push_up(int k) {
        if (a[k].cnt) a[k].len = a[k].r - a[k].l;
        else a[k].len = a[k << 1].len + a[k << 1 | 1].len;
    }

    void build(int k, int l, int r) {
        a[k].l = q[l], a[k].r = q[r];
        a[k].cnt = a[k].len = 0;
        if (r - l == 1) return;
        int mid = (l + r) >> 1;
        build(k << 1, l, mid);
        build(k << 1 | 1, mid, r);
    }

    void modify(int k, double p, double q, int v) {
        double l = a[k].l, r = a[k].r;
        if (l >= p && r <= q) {
            a[k].cnt += v;
            push_up(k);
            return;
        }
        if (a[k << 1].r > p) modify(k << 1, p, q, v);
        if (a[k << 1 | 1].l < q) modify(k << 1 | 1, p, q, v);
        push_up(k);
    }

    void init(int m, vector<double> &p) {
        n = m, q = p;
        build(1, 0, n - 1);
    }

    void change(double x1, double x2, int v) {
        modify(1, x1, x2, v);
    }

    double calc() {
        return a[1].len;
    }
}

double Main(int n) {
    vector<double> s;
    vector<query> q;
    for (int i = 0; i < n; ++i) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        owap(x1, x2), owap(y1, y2);
        s.push_back(x1), s.push_back(x2);
        q.emplace_back(x1, x2, y1, 1);
        q.emplace_back(x1, x2, y2, -1);
    }
    sort(q.begin(), q.end());
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    seg::init((int)s.size(), s);
    double ans = 0;
    for (int i = 0; i + 1 < (int)q.size(); ++i) {
        seg::change(q[i].x1, q[i].x2, q[i].v);
        ans += seg::calc() * (q[i + 1].y - q[i].y);
    }
    return ans;
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    int n, tot = 0;
    while (cin >> n && n)
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++tot, Main(n));
    return 0;
}