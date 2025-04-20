#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void Main() {
    string s, t;
    cin >> s >> t;
    if (s == t)
        puts("0");
    else {
        while (s.size() < t.size())
            s.push_back('#');
        while (t.size() < s.size())
            t.push_back('#');
        assert(s.size() == t.size());
        int n = s.size();
        for (int i = 1; i <= n; ++i)
            if (s[i - 1] != t[i - 1]) {
                cout << i << endl;
                break;
            }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}

