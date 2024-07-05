#pragma GCC optimize(1,2,"Ofast,fast-math")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define endl '\n'
#define gcd(a, b) __gcd(a, b)

#define in(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
#define is(x, y) (a[x][y] == '#')

constexpr int N = 1010;
constexpr ll mod = 998244353;

constexpr int dx[4] = {-1, 0, 0, 1};
constexpr int dy[4] = {0, -1, 1, 0};

int n, m;
string a[N];
int sys[N][N];

int tot;
void dfs(int x, int y, int k) {
    sys[x][y] = k; rep(i, 4) {
        int tx = x + dx[i], ty = y + dy[i];
        if (in(tx, ty) && is(tx, ty) && !sys[tx][ty]) dfs(tx, ty, k);
    }
}

int solve(int x, int y) {
    set<int> app; rep(i, 4) {
        int tx = x + dx[i], ty = y + dy[i];
        if (in(tx, ty) && is(tx, ty)) app.emplace(sys[tx][ty]);
    }  return tot - app.size() + 1;
}

ll qpow(ll a, ll b, ll p) {
    ll r = 1; for (; b; b >>= 1) {
        if (b & 1) r = r * a % p;
        a = a * a % p;
    } return r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m; int res = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] = " " + a[i] + " ";
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (is(i, j) && !sys[i][j]) dfs(i, j, ++tot);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (!is(i, j)) (res += solve(i, j) % mod) %= mod, ++cnt;
    cerr << res << " / " << cnt << endl;
    cout << res * qpow(cnt, mod - 2, mod) % mod << endl;
    return 0;
}
