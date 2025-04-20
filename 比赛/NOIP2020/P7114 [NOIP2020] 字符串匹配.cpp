#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define endl "\n"
#define gc() getchar_unlocked()

#define SWS ios::sync_with_stdio(false)
#define TIE cin.tie(nullptr), cout.tie(nullptr)

inline int readint() {
    int n = 0, c = gc();
    while (!isdigit(c)) c = gc();
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return n;
}

inline string readstr() {
    string str;
    int c = gc();
    if (c == '\n') c = gc();
    while (c != '\n') str.push_back(c), c = gc();
    return str;
}

constexpr int N = 1 << 21;

using ll = long long;
using htp = unsigned long long;

constexpr htp mod1 = 1e9 + 7;
constexpr htp mod2 = 1e9 + 9;

constexpr htp base1 = 53;
constexpr htp base2 = 97;

htp frac1[N], frac2[N];
htp h1[N], h2[N];

constexpr void init() {
    frac1[0] = frac2[0] = 1;
    gor(i, 1, N) frac1[i] = frac1[i - 1] * base1 % mod1;
    gor(i, 1, N) frac2[i] = frac2[i - 1] * base2 % mod2;
}

inline htp get1(int l, int r) { return l ? (h1[r] - h1[l - 1] * frac1[r - l + 1] % mod1 + mod1) % mod1 : h1[r]; }
inline htp get2(int l, int r) { return l ? (h2[r] - h2[l - 1] * frac2[r - l + 1] % mod2 + mod2) % mod2 : h2[r]; }

int s[N], n;
inline int lobit(int x) {
    return x & -x;
} int query(int x) {
    int r = 0;
    for (++x; x; x -= lobit(x)) r += s[x];
    return r;
} void add(int x) {
    for (++x; x <= n; x += lobit(x)) ++s[x];
}

int rcnt[N], appear[30];

void build(string str) {
    h1[0] = h2[0] = str[0];
    n = str.size(); gor(i, 1, n) {
        h1[i] = (h1[i - 1] * base1 % mod1 + str[i]) % mod1;
        h2[i] = (h2[i - 1] * base2 % mod2 + str[i]) % mod2;
    }  rcnt[n] = 0;
    memset(appear, 0, sizeof appear);
    for (int i = n - 1; ~i; --i)
        rcnt[i] = rcnt[i + 1] + ((++appear[str[i] - 'a'] & 1) ? 1 : -1), s[i + 1] = 0;
}

void solve(string str) {
    build(str); memset(appear, 0, sizeof appear);
    ++appear[str[0] - 'a'], add(1); int f = 1;
    ll ans = 0; gor(len, 2, n) {
        ll res = query(rcnt[len]);
        htp k1 = h1[len - 1], k2 = h2[len - 1];
        for (int l = len; l + len < n; l += len) {
            int r = l + len - 1;
            if (get1(l, r) != k1 || get2(l, r) != k2) break;
            res += query(rcnt[r + 1]);
        } f = f + ((++appear[str[len - 1] - 'a'] & 1) ? 1 : -1);
        add(f); ans += res;
    } printf("%lld\n", ans);
}

signed main() {
    SWS; TIE; init();
    int T = readint();
    while (T--) solve(readstr());
    return 0;
}
