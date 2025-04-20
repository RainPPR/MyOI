// rp++ what do your do at the end of the world?
// Y@2L32#
// T#YMS@4
// node: 0+998244710

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define endl '\n'

#define open(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(nullptr), cout.tie(nullptr)

signed main() {
    // if there is a Maxi < it : 0
    // else if all the strings are greater than it : 1
    // note: less, not less-equal
    // greedy?
    open("dict"); IOS; TIE;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    string tar = "-1";
    for (string i : s) {
        sort(i.begin(), i.end(), greater<void>());
        if (tar == "-1" || i < tar) tar = i;
    } for (string i : s) {
        sort(i.begin(), i.end());
        if (tar < i) cout << 0;
        else cout << 1;
    } cout << endl;
    /*rep(i, n) {
        sort(s[i].begin(), s[i].end());
        cout << s[i] << " ";
        sort(s[i].begin(), s[i].end(), greater<char>());
        cout << s[i] << endl;
    }*/ return 0;
}
