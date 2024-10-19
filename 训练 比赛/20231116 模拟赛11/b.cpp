#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++j)

#define gc() getchar_unlocked()
#define endl '\n'

#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) < 0 ? -(x) : (x))
#define Swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

#define open(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

const ll mod = 1e9 + 7;

pair<ll, ll> Main(vector<int> p) {
    int n = p.size(); vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for (ll step = 0, sum = 0; ; step = (step + 1) % mod) {
        if (a == p) return {step, sum};
        int down = n - 2, mini = -1;
        while (a[down] >= a[down + 1]) --down;
        for (int i = down + 1; i < n; ++i)
            if (a[i] > a[down] && (mini == -1 || a[i] < a[mini]))
                mini = i;
        ll rev = n - down - 2;
        sum += rev * (rev - 1) / 2 + n - down - 1;
        sum %= mod;
        swap(a[mini], a[down]);
        reverse(next(a.begin(), down + 1), a.end());
    } return {-1, 0};
}

int main() {
    open("prem");
    int n = rr; vector<int> a(n);
    rep(i, n) a[i] = rr;
    auto ans = Main(a);
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}
