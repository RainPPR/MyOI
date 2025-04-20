#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

using i2 = __int128;

int d;

string build_and(vector<string> op) {
    int n = op.size();
    string str;
    rep(i, d) {
        bool wow = false, qwq = false;
        rep(j, n)
            if (op[j][i] == '0') {
                wow = true;
                break;
            } else if (op[j][i] == '?') {
                qwq = true;
            }
        if (wow) str.push_back('0');
        else if (qwq) str.push_back('?');
        else str.push_back('1');
    } return str;
}

string build_or(vector<string> op) {
    int n = op.size();
    string str;
    rep(i, d) {
        bool wow = false, qwq = false;
        rep(j, n)
            if (op[j][i] == '1') {
                wow = true;
                break;
            } else if (op[j][i] == '?') {
                qwq = true;
            }
        if (wow) str.push_back('1');
        else if (qwq) str.push_back('?');
        else str.push_back('0');
    } return str;
}

void write(i2 x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar('0' + int(x % 10));
}

void solve() {
    int n; cin >> n >> d;
    string op; cin >> op;

    string now; cin >> now;
    rep(i, n - 1) {
        string str; cin >> str;
        if (op[i] == '0') now = build_and({now, str});
        else now = build_or({now, str});
    }

    i2 ans = 1;
    for (auto i : now) {
        if (i == '?') ans <<= 1;
    }

    write(ans);
    putchar('\n');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
