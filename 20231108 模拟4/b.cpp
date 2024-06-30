#include <bits/stdc++.h>

using namespace std;

mt19937 rd(time(0) * clock());

signed main() {
    long long n, m;
    cin >> n >> m;
    if (m == LLONG_MAX) --m;
    while (n--)
        cout << rd() % (m + 1) << " ";
    return 0;
}
