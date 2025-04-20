#include <cstdio>

using namespace std;

const int N = 1e5 + 10;
int cnt[N];

int main()
{
	int n, k, x;
	scanf("%d %d", &n, &k);

	long long now = 0, ans = 0;
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &x);
		++cnt[now];
		now = (now + x) % k;
		ans += cnt[now];
	}

	printf("%lld", ans);
	return 0;
}
