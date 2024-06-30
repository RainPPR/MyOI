#include <bits/stdc++.h>

using namespace std;

#define gcd(a, b) __gcd(a, b)

int phi(int n) {
    int r = n;
    for (int i = 2, u = sqrt(n); i <= u; ++i) {
        if (n % i) continue;
        r = r / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) r = r / n * (n - 1);
    return r;
}

int qpow(int a, int b, int p) {
    int r = 1; a %= p;
    for (; b; b >>= 1) {
        if (b & 1) r = r * a % p;
        a = a * a % p;
    } return r;
}

void solev() {
    int m, h, r = 0; cin >> m >> h;
    int pm = phi(m); while (h--) {
        int a, b; cin >> a >> b;
        if (gcd(a, m) == 1) r = (r + qpow(a, b % pm, m)) % m;
        else if (b < pm) r = (r + qpow(a, b, m)) % m;
        else r = (r + qpow(a, b % pm + pm, m)) % m;
    } cout << r << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solev();
    return 0;
}