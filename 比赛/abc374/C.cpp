#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void brute() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int ans = 2e9;
    for (int s = 0; s < (1 << n); ++s) {
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i)
            if ((s >> i) & 1)
                x += a[i];
            else
                y += a[i];
        ans = min(max(x, y), ans);
    }
    cout << ans << endl;
}

void Main() {
    brute();
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}

