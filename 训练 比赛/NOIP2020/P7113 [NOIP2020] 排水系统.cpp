#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define endl "\n"
#define gc() getchar_unlocked()

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

inline void write(__int128 x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(int(x % 10 + '0'));
}

using ll = long long;

template<typename tp>
inline tp gcd(tp a, tp b) { return b ? gcd(b, a % b) : a; }
#define lcm(a, b) ((a) / gcd(a, b) * (b))

template<typename tp>
struct frac {
    tp fz, fm;
    void tidy() { tp t = gcd(fz, fm); fz /= t, fm /= t; }
    void print() { write(fz), putchar(' '), write(fm), putchar('\n'); }
    frac() { fz = 0, fm = 1; }
    frac(tp a) { fz = a, fm = 1; }
    frac(tp a, tp b) { fz = a, fm = b; tidy(); }
    frac operator/(tp x) { return frac(fz, fm * x); }
    frac operator*(tp x) { return frac(fz * x, fm); }
    frac operator+(frac<tp> x) {
        if (fz == 0) return x;
        if (x.fz == 0) return *this;
        else {
            tp nm = lcm(fm, x.fm);
            return frac(nm / fm * fz + nm / x.fm * x.fz, nm);
        }
    }
};

using TP = __int128;

vector<vector<int>> g;
vector<frac<TP>> flow;

vector<int> in, non;

signed main() {
    int n = rr, m = rr;
    g.resize(n + 1); in.resize(n + 1);
    auto get = [&] (int u) {
        int d = rr, t; if (!d) non.push_back(u);
        while (d--) t = rr, g[u].push_back(t), ++in[t];
    }; rep(i, n) get(i + 1);
    flow.resize(n + 1); queue<int> q;
    rep(i, m) flow[i + 1] = 1, q.push(i + 1);
    while (q.size()) {
        int u = q.front(); q.pop();
        if (!g[u].size()) continue;
        frac<TP> ad(flow[u] / g[u].size());
        for (int v : g[u]) {
            flow[v] = flow[v] + ad, --in[v];
            if (!in[v]) q.push(v);
        }
    } for (int i : non) flow[i].print();
    return 0;
}
