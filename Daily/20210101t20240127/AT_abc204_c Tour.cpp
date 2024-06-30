#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define gc() getchar_unlocked()
#define rr read()

inline int read() {
    int n = 0, c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

int main() {
    int n = rr, m = rr, res = 0;
    vector<vector<int>> g(n + 1);
    while (m--) {
        int a = rr, b = rr;
        g[a].push_back(b);
    } for (int i = 1; i <= n; ++i) {
        unordered_set<int> vis;
        queue<int> q; q.push(i);
        while (q.size()) {
            auto u = q.front(); q.pop();
            vis.insert(u); for (int &v : g[u])
            if (!vis.count(v)) q.push(v);
        } res += vis.size();
    } printf("%d\n", res); return 0;
}
