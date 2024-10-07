#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 110;

using ll = long long;

#define int ll

int n, k, x;

int t[N];

int dp[N * N][N];

int calc(const vector<int> &s) {
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    int res = 8e18;
    for (int i = 0, nxt = 0; i < s.size(); ++i) {
        while (nxt < s.size() && s[nxt] < s[i] + x)
            ++nxt;
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] > (0x3f3f3f3f3f3f3f3f >> 1))
                continue;
            int now = dp[i][j];
            dp[i + 1][j] = min(dp[i + 1][j], now);
            for (int m = j; m < min(j + k, n); ++m) {
                if (t[m] > s[i])
                    break;
                now += s[i] - t[m];
                if (m == n - 1)
                    res = min(res, now);
                else if (nxt < s.size())
                    dp[nxt][m + 1] = min(dp[nxt][m + 1], now);
            }
        }
    }
}

void Main() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    vector<int> s; 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j)
            s.push_back(t[i] + j * x);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    cout << calc(s) << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}

