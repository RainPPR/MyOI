#include <bits/stdc++.h>

using namespace std;

void solev() {
    int id; cin >> id;
    int n, mid; cin >> n >> mid;
    priority_queue<int> cmin;
    priority_queue<int, vector<int>, greater<int>> cmax;
    for (int i = 2; i <= n; ++i) {
        int a; cin >> a;
        if (a < mid) cmin.push(a);
        else cmax.push(a);
        if (i % 2 == 0) continue;
        while (cmin.size() > cmax.size()) {
            a = cmin.top(); cmin.pop();
            cmax.push(mid), mid = a;
        }
        while (cmax.size() > cmin.size()) {
            a = cmax.top(); cmax.pop();
            cmin.push(mid), mid = a;
        }
        cout << mid << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solev();
    return 0;
}