#include <cstdio>
#include <unordered_set>

using namespace std;

int main()
{
	int T, n, x;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		unordered_multiset<int> s;
		while (n--)
		{
			scanf("%d", &x);
			s.emplace(x);
		}

		int cnt = 0;
		for (int i : s)
			if (s.count(i * 2))
				++cnt;

		printf("%d\n", cnt);
	}

	return 0;
}
