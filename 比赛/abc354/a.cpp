#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

template<typename tp>
istream& operator >>(istream &in, vector<tp> &a) {
    for (tp &t : a) in >> t;
    return in;
}

template<typename tp>
ostream& operator <<(ostream &out, vector<tp> &a) {
    for (auto i : a) out << i << " ";
    return out;
}

#define range(x) x.begin(), x.end()
#define lowbit(x) ((x) & -(x))

constexpr int N = 2e5 + 10;

int n, res;

vector<int> lis(vector<int> &a, int &e) {
    vector<int> dp(n, 2e9), ret(n);
    dp[0] = 0; for (int i = 0; i < n; ++i) {
        int id = lower_bound(dp.begin(), dp.end(), a[i]) - dp.end();
        dp[id] = a[i], ret[i] = id;
    } return ret;
}

void solev() {
    cin >> n;
    vector<int> a(n), pre, suf, r;
    cin >> a;
    pre = lis(a, res);
    reverse(range(a)); for (auto &i : a) i = -i;
    suf = lis(a, res);
    for (int i = 0; i < n; ++i) if (pre[i] + suf[n - i - 1] - 1 == res) r.push_back(i + 1);
    cout << r.size() << endl << r << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solev();
    return 0;
}