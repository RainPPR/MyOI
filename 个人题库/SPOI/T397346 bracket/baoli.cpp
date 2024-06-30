#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

using ll = long long;

constexpr ll mod = 998244353;

#define add(x, t, p) x = (x + (t) % p + p) % p

bool check(string s) {
    stack<char> op;
    for (char c : s) {
        if (c == '(') op.push(c);
        else if (op.empty() || op.top() != '(') return false;
        else op.pop();
    } return op.empty();
}

ll solve(string S) {
    int n = S.size();
    vector<string> s = {"", S.substr(0, 1)};
    gor(i, 1, n) {
        auto bak = s;
        for (string t : bak) s.push_back(t + S.substr(i, 1));
    } ll res = 0; for (string t : s) if (check(t))
        if (++res == mod) res = 0;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; string s; cin >> T;
    while (T--) cout << solve((cin >> s, s)) << endl;
    return 0;
}
