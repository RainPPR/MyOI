#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void Main() {
    int a, b, k;
    cin >> a >> b >> k;
    int n = a + b;
    if (k > a) {
        cout << "No" << endl;
        return;
    }
    string s;
    string t;
    for (int i = 1; i <= k; ++i)
        s.push_back('0');
    t.push_back('1');
    for (int i = 1; i < k; ++i)
        t.push_back('1');
    for (int i = 1; i < b; ++i) {
        s.push_back('1');
        t.push_back('1');
    }
    while ((int)s.size() < n) {
        s.push_back('0');
        t.push_back('0');
    }
    cout << "Yes" << endl;
    cout << s << endl;
    cout << t << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}