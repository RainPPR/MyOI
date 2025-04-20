// T2: 中间的限制

#include <cstdio>
#include <cstring>

using namespace std;

const int N = 8005;

int a[N], cnt[N * 2];
int ans[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", &a[i]);

	for (int i = 1 ; i <= n ; ++i)
	{
		memset(cnt, 0, sizeof cnt);
		cnt[8000] = 1;

		int sum = 0;
		for (int j = 1 ; j < i ; ++j)
		{
			if (a[j] < a[i])
				sum++;
			else if (a[j] > a[i])
				sum--;
			cnt[8000 + sum]++;
		}

		for (int j = i ; j <= n ; ++j)
		{
			if (a[j] < a[i])
				sum++;
			else if (a[j] > a[i])
				sum--;
			ans[i] += cnt[8000 + sum];
		}
	}

	for (int i = 1 ; i <= n ; ++i)
		printf("%d ", ans[i]);
	return 0;
}

