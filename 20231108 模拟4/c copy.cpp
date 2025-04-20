#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = l; i < r; ++i)

#define dg(c) isdigit(c)
#define gc() getchar_unlocked()
#define endl '\n'

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !dg(c); c = gc()) f |= c == '-';
    for (; dg(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

using ll = long long;

constexpr int INF = 0x3f3f3f3f;

int n;

vector<vector<int>> g;

namespace sub12 {
    vector<int> getdis() {
        vector<int> vis(n), dis(n);
        fill(dis.begin(), dis.end(), INF);
        dis[0] = 0;
        rep(i, n) {
            int u = -1;
            rep(j, n)
                if (!vis[j] && (u == -1 || dis[j] < dis[u]))
                    u = j;
            vis[u] = 1;
            rep(v, n)
                if(dis[v] > dis[u] + g[u][v])
                    dis[v] = dis[u] + g[u][v];
        } return dis;
    } ll calc() {
        vector<int> correct = getdis();
        vector<int> p(n);
        rep(i, n) p[i] = i;
        ll ans = 0;
        vector<int> dis(n);
        do {
            fill(dis.begin(), dis.end(), INF);
            dis[0] = 0;
            for (int u : p) {
                rep(v, n)
                    if(dis[v] > dis[u] + g[u][v])
                        dis[v] = dis[u] + g[u][v];
            } ans += dis == correct;
        } while (next_permutation(p.begin(), p.end()));
        return ans;
    }
}

namespace sub3 {
    ll calc() {
        ll r = 1;
        rep(i, n) r *= i + 1;
        return r;
    }
}

signed main() {
    n = rr;
    g = vector<vector<int>>(n, vector<int>(n));
    bool issub3 = true;
    rep(u, n) rep(v, n) {
        g[u][v] = rr;
        if (u != v && g[u][v] != 1)
            issub3 = false;
    } if (issub3) {
        printf("%lld\n", sub3::calc());
    } else {
        printf("%lld\n", sub12::calc());
    } return 0;
}
