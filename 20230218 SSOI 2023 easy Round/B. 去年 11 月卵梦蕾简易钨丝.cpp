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

		map<int, int>::iterator l = num.begin(), r = num.end();
		--r;
		int ans = 2 * (r->first - l->first);
		printf("%d\n", ans);
	}
	return 0;
}
