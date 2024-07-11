#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5010;

int n;

bool a[N], c[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char op[2];
        cin >> op;
        a[i] = op[0] == 'F';
    }
    int ops = 1e9, siz = 0;
    for (int len = 1; len <= n; ++len) {
        memset(c, 0, sizeof c);
        bool C = 0, flag = 1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            C ^= c[i];
            if ((a[i] ^ C) == 0) {
                int r = i + len - 1;
                if (r > n) {
                    flag = 0;
                    break;
                }
                C ^= 1;
                c[r + 1] ^= 1;
                ++cnt;
            }
        }
        if (flag) {
            if (cnt < ops)
                ops = cnt, siz = len;
        }
    }
    cout << siz << " " << ops << endl;
    return 0;
}