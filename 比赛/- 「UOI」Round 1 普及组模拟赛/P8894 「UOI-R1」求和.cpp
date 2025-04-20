#include <cstdio>
#include <algorithm>
#define MAX(A, B) ((A > B) ? A : B)

using namespace std;

const int MOD = 998244353;
const int N = 5e3 + 10;

pair<int, int> arr[N];

int n;
long long ans;

void dfs(int now, int m)
{
	if (now == n)
	{
		ans = (ans + m) % MOD;
		return ;
	}

	for (int i = arr[now].first ; i <= arr[now].second ; ++i)
		dfs(now + 1, MAX(m, i));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	dfs(0, 0);

	printf("%lld", ans);
	return 0;
}
