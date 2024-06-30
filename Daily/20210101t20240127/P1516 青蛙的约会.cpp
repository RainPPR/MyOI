// https://www.luogu.com.cn/paste/txmx08s2
// https://www.cnblogs.com/RainPPR/p/linear-congruence-equation-and-inverse.html

#include <bits/stdc++.h>

#define int long long

using namespace std;

inline int exgcd(int a, int b, int &x, int &y) {
    if (!b) return (x = 1, y = 0, a);
    int d = exgcd(b, a % b, y, x);
    return (y -= a / b * x, d);
}

// ax + by = n (rt. a)
inline int solev(int a, int b, int n) {
    int x, y, d = exgcd(a, b, x, y);
    if (n % d) return -1;
    int t = b / d;
    return ((x * (n / d)) % t + t) % t;
    // return (x % t + t) % t; // native x
}

signed main() {
    int x, y, m, n, L, W, S;
    cin >> x >> y >> m >> n >> L;
    if (n >= m) W = n - m, S = x - y;
    else W = m - n, S = y - x;
    int res = solev(W, L, S);
    if (res != -1) cout << res << endl;
    else cout << "Impossible" << endl;
    return 0;
}
