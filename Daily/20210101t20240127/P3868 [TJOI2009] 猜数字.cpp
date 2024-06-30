#include <bits/stdc++.h>

using ll = long long;
#define int ll

using namespace std;

int Mul(int a, int b, int p) {
    int r = 0;
    for (; b; b >>= 1) {
        if (b & 1) (r += a) %= p;
        (a += a) %= p;
    } return r;
}

int Pow(int a, int b, int p) {
    int r = 1;
    for (; b; b >>= 1) {
        if (b & 1) r = Mul(r, a, p);
        a = Mul(a, a, p);
    } return r;
}

int exgcd(int a, int b, int &x, int &y) {
    if (!b) return (x = 1, y = 0, a);
    int d = exgcd(b, a % b, y, x);
    return (y -= a / b * x, d);
}

int inv(int a, int m) {
    int x, y; exgcd(a, m, x, y);
    return (x % m + m) % m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, M = 1; cin >> n;
    vector<int> a(n), m(n);
    for (int &i : a) cin >> i;
    for (int &i : m) cin >> i, M *= i;
    int res = 0; for (int i = 0; i < n; ++i) {
        ll t = M / m[i], c = inv(t, m[i]);
        res = (res + Mul(a[i], Mul(t, c, M), M)) % M;
    } cout << res << endl;
    return 0;
}