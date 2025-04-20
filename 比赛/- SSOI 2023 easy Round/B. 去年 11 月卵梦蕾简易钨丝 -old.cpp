#include <cstdio>
#include <map>

using namespace std;

map<int, int> num;

int n, q;

int main()
{
	int a;
	scanf("%d %d", &n, &q);
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d", &a);
		++num[a];
	}

	int opt, x;
	for (int i = 0 ; i < q ; ++i)
	{
		scanf("%d %d", &opt, &x);

		if (opt == 2)
			++num[x];
		else
		{
			if (num.count(x) != 0)
			{
				--num[x];
				if (num[x] == 0)
					num.erase(x);
			}
			else
			{
				printf("-1\n");
				continue;
			}
		}

		int ans = 0;
		map<int, int>::iterator a = num.begin(), k = num.begin();
		for (++k ; k != num.end() ; ++a, ++k)
			ans += k->first - a->first;
		ans += a->first - num.begin()->first;
		printf("%d\n", ans);
	}
	return 0;
}
