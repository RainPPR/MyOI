#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read<int>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

#define turn(x) ((x) = -(x))
#define change(a, b) (tie(a, b) = make_tuple(-b, -a))

struct node {
    int x, y;
    pair<int, int> p2() { return make_pair(x, y); }
    tuple<int, int> t3() { return make_tuple(x, y); }
};

inline int dist(int a, int b, int c, int d) { return abs(a - c) + abs(b - d); }
inline int dist(node a, node b) { return dist(a.x, a.y, b.x, b.y); }

vector<node> a;

signed main() {
    int id = rr, n = rr, q = rr;

    a.resize(n);
    rep(i, n) a[i].x = rr, a[i].y = rr;

    auto query_native = [&] (node s, node t, int lx, int rx, int ly, int ry, int tn) {
        int r1 = 0, r2 = 0, r3 = 0;
        for (int x = lx; x <= rx; ++x) for (int y = ly; y <= ry; ++y) {
            int a = dist(s.x, s.y, x, y);
            int b = dist(t.x, t.y, x, y);
            if (a > b) ++r1;
            else if (a < b) ++r2;
            else ++r3;
        } return make_tuple(tn ? r2 : r1, tn ? r1 : r2, r3);
    };

    auto query_eq = [&] (node s, node t, int lx, int rx, int ly, int ry) {
        return -1;
    };

    auto query_left = [&] (node s, node t, int lx, int rx, int ly, int ry) {
        float b = ((s.y + t.y) / 2.0) - ((s.x + t.x) / 2.0);
        float yp = s.x + b;
        if (yp <= s.y) return 0;
        return -1;
    };

    auto query_right = [&] (node s, node t, int lx, int rx, int ly, int ry) {
        float b = ((s.y + t.y) / 2.0) - ((s.x + t.x) / 2.0);
        float yp = t.x + b;
        if (yp >= t.y) return 0;
        return -1;
    };

    auto query = [&] () {
        auto s = a[rr - 1], t = a[rr - 1];
        int lx = rr, rx = rr, ly = rr, ry = rr;
        int tn = 0;
        if (s.x > t.x) swap(s, t), tn = 1;
        if (s.y > t.y) turn(s.y), turn(t.y), change(ly, ry);
        lx -= s.x, rx -= s.x, t.x -= s.x, s.x = 0;
        ly -= s.y, ry -= s.y, t.y -= s.y, s.y = 0;
        int dis = dist(s, t);
        int a = query_left(s, t, lx, rx, ly, ry);
        int b = query_right(s, t, lx, rx, ly, ry);
        int c = (dis & 1) ? 0 : query_eq(s, t, lx, rx, ly, ry);
        return make_tuple(tn ? b : a, tn ? a : b, c);
    };
    
    auto print = [&] (tuple<int, int, int> t) {
        int a, b, c; tie(a, b, c) = t;
        printf("%d %d %d\n", a, b, c);
    };
    
    while (q--) print(query());
    return 0;
}
