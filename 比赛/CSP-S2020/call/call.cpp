#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

#define int ll

constexpr int mod = 998244353;
constexpr int N = 1e5 + 10;

int n, m;
int val[N];

int op[N];
int pos[N], add[N];
int mul[N];

vector<int> G[N];
vector<int> R[N];

int cnt[N];

int deg1[N];

void top_sort_1() {
    queue<int> q;
    for (int i = 0; i <= m; ++i) {
        deg1[i] = G[i].size();
        if (deg1[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : R[u]) {
            mul[v] = mul[v] * mul[u] % mod;
            if (--deg1[v] == 0)
                q.push(v);
        }
    }
}

int deg2[N];

void top_sort_2() {
    queue<int> q;
    for (int i = 0; i <= m; ++i) {
        deg2[i] = R[i].size();
        if (deg2[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int now = 1;
        for (auto it = G[u].rbegin(); it != G[u].rend(); ++it) {
            int v = *it;
            cnt[v] = (cnt[v] + cnt[u] * now % mod) % mod;
            now = now * mul[v] % mod;
            if (--deg2[v] == 0)
                q.push(v);
        }
    }
}

void Main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    cin >> m;
    mul[0] = 1;
    for (int i = 1; i <= m; ++i) {
        cin >> op[i];
        mul[i] = 1;
        switch (op[i]) {
            case 1:
                cin >> pos[i] >> add[i];
                break;
            case 2:
                cin >> mul[i];
                break;
            case 3:
                int c;
                cin >> c;
                while (c--) {
                    int g;
                    cin >> g;
                    G[i].push_back(g);
                    R[g].push_back(i);
                }
                break;
            default: ;
        }
    }
    cnt[0] = 1;
    int Q;
    cin >> Q;
    while (Q--) {
        int x;
        cin >> x;
        G[0].push_back(x);
        R[x].push_back(0);
    }
    top_sort_1();
    top_sort_2();
//    for (int i = 0; i <= m; ++i)
//        cerr << "| " << i << ": " << mul[i] << " " << cnt[i] << endl; 
    for (int i = 1; i <= n; ++i)
        val[i] = val[i] * mul[0] % mod;
    for (int i = 1; i <= m; ++i)
        if (op[i] == 1)
            val[pos[i]] = (val[pos[i]] + cnt[i] * add[i] % mod) % mod;
    for (int i = 1; i <= n; ++i)
        cout << val[i] << " ";
    return;
}

signed main() {
    // freopen("call3.in", "r", stdin);
    // freopen("call.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}
