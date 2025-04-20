#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

#define endl '\n'
#define gc() getchar_unlocked()

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return n;
}

struct edge { int u, v; };

int n, m;
vector<vector<int>> g;

vector<int> _in;

using psmall = priority_queue<int, vector<int>, greater<int>>;
using plarge = set<int>;

namespace s1 {
    int solve() {
        vector<int> in(_in); psmall q;
        rep(i, n) if (!in[i]) q.push(i);
        int res = 0, lt = -1;
        while (q.size()) {
            int u = q.top(); q.pop();
            if (u > lt) ++res, lt = u;
            for (int v : g[u])
                if (--in[v] == 0) q.push(v);
        } return res;
    }
}

namespace s2 {
    int solve() {
        vector<int> in(_in); plarge q;
        rep(i, n) if (!in[i]) q.insert(i);
        int res = 0, lt = -1;
        while (q.size()) {
            int u;
            if (*q.begin() < lt) u = *q.begin(), q.erase(q.begin());
            else u = *(--q.end()), q.erase(--q.end());
            if (u > lt) ++res, lt = u;
            for (int v : g[u])
                if (--in[v] == 0) q.insert(v);
        } return res;
    }
}

signed main() {
    n = rr, m = rr;
    g.resize(n); _in.resize(n);
    rep(i, m) {
        int u = rr - 1, v = rr - 1;
        ++_in[v], g[u].push_back(v);
    } printf("%d\n%d\n", s1::solve(), s2::solve());
    return 0;
}
