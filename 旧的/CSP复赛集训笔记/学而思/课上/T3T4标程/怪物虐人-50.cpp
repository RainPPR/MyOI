#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 505;
int a[N], n, k;
int ans = 1e9;
void dfs(int step, int left, int cost)
{
    if (step > n)
    {
        ans = min(ans, cost);
        return;
    }
    else
    {
        int maxx = 0;
        for (int i = step; i <= n; ++i)
        {
            maxx = max(maxx, a[i]);
            if (left) dfs(i + 1, left - 1, cost + maxx * (i - step + 1));
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dfs(1, k, 0);
    cout << ans << endl;
    return 0;
}
