#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

auto dist = [] (int x, int y, int z, int w) {
//    cerr << "[" << x << ", " << y << "] -> [" << z << ", " << w << "]" << endl;
    return sqrt(1.0 * (x - z) * (x - z) + 1.0 * (y - w) * (y - w));
};

int n, s, t;
    
struct node {
    int a, b, c, d;
};

vector<node> q;

double ans = 1e18;

int vis[10];

void dfs(int k, int x, int y, double res) {
    if (k == q.size()) {
        ans = min(ans, res);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i])
            continue;
        vis[i] = true;
        dfs(k + 1, q[i].c, q[i].d, res + dist(x, y, q[i].a, q[i].b) + dist(q[i].a, q[i].b, q[i].c, q[i].d));
        dfs(k + 1, q[i].a, q[i].b, res + dist(x, y, q[i].c, q[i].d) + dist(q[i].c, q[i].d, q[i].a, q[i].b));
        vis[i] = false;
    }
}

void Main() {
    cin >> n >> s >> t;
    q.resize(n);
    for (auto &[a, b, c, d] : q)
        cin >> a >> b >> c >> d;
    dfs(0, 0, 0, 0);
    printf("%.9lf\n", ans);
//    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}

