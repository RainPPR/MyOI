#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

#ifdef __linux__
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif

using ll = long long;

inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = n * 10 + c - '0';
    return f ? -n : n;
}

int n, m;

vector<vector<int>> a;
vector<vector<ll>> sum;

ll getsum(int a, int b, int c, int d) {
    return sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
}

bool check(int mid) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i][j] = (a[i][j] >= mid) + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
    const ll tar = 1ll * mid * mid;
    for (int i = 1; i + mid - 1 <= n; ++i)
        for (int j = 1; j + mid - 1 <= m; ++j)
            if (getsum(i, j, i + mid - 1, j + mid - 1) >= tar)
                return true;
    return false;
}

void Main() {
    n = read(), m = read();
    a.clear(), a.shrink_to_fit();
    a.resize(n + 1, vector<int>(m + 1));
    sum.clear(), sum.shrink_to_fit();
    sum.resize(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = read();
    int l = 1, r = min(n, m);
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = read();
    while (T--) Main();
    return 0;
}