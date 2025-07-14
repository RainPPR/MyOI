#include <cstdio>
#include <unordered_map>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int m, p, q, a;
		scanf("%d", &m);

		int ans = 0;
		unordered_map<int, int> cnt;
		while (m--)
		{
			scanf("%d %d", &p, &q);
			while (q--)
			{
				scanf("%d", &a);
				a *= p, ++cnt[a];
				if (cnt[a] > ans)
					ans = cnt[a];
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
