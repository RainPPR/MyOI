#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 505;
int a[N], n, k;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 1e9;
    for (int i = 1; i <= n; ++i)
    {
        int cost = 0, maxx = 0;
        for (int j = 1; j < i; ++j)
        {
            maxx = max(maxx, a[j]);
        }
        cost += maxx * (i - 1);
        maxx = 0;
        for (int j = i; j <= n; ++j)
        {
            maxx = max(maxx, a[j]);
        }
        cost += maxx * (n - i + 1);
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}
