#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll Pow(ll a, ll b, ll p) {
    ll r = 1;
    for (; b; b >>= 1) {
        if (b & 1) r = (__int128)r * a % p;
        a = (__int128)a * a % p;
    } return r;
}

bool Miller_Rabbin(ll a, ll n) {
    ll s = n - 1, r = 0;
    while ((s & 1) == 0) s >>= 1, ++r;
    ll k = Pow(a, s, n);
    if (k == 1) return true;
    for (int i = 0; i < r; ++i) {
        if (k == n - 1) return true;
        k = (__int128)k * k % n;
    } return false;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    ll cnt = 7, pri[10] = {2, 3, 4, 5, 11, 233, 331};
    for (int i = 0; i < cnt; ++i) {
        if (n == pri[i]) return true;
        if (!Miller_Rabbin(pri[i], n)) return false;
    } return true;
}

mt19937 rd(time(0) * clock() + 19260817);
inline ll Abs(ll x) { return x < 0 ? -x : x; }
#define gcd(a, b) __gcd(a, b)

ll Pollard_Rho(ll x) {
    ll s = 0, t = 0, val = 1, d;
    ll c = (ll)rd() % (x - 1) + 1;
    for (int goal = 1; ; goal *= 2, s = t, val = 1) {
        for (ll step = 1; step <= goal; ++step) {
            t = ((__int128)t * t + c) % x;
            val = (__int128)val * Abs(s - t) % x;
            if (!val) return x;
            if (step % 127 == 0)
            if ((d = gcd(val, x)) > 1) return d;
        } if ((d = gcd(val, x)) > 1) return d;
    } return -1;
}

ll res;

void dfs(ll x) {
    if (x <= res || x < 2) return;
    if (isPrime(x)) return void(res = x);
    ll p = x;
    while (p >= x) p = Pollard_Rho(x);
    while (x % p == 0) x /= p;
    dfs(x), dfs(p);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        res = 0; ll n; cin >> n; dfs(n);
        if (n == res) cout << "Prime" << endl;
        else cout << res << endl;
    } return 0;
}