#include <cstdio>
#include <map>

using namespace std;

const int N = 5e5 + 10;

int a[N];

namespace St
{
	map<int, int> cnt;

	void insert(int x)
	{
		++cnt[x];
	}

	void remove(int x)
	{
		--cnt[x];
		if (cnt[x] == 0)
			cnt.erase(x);
	}

	long long get_ans()
	{
		long long ans = 1;

		map<int, int>::iterator i = cnt.begin();

		if (i->second > 1)
			return 0;

		for (++i ; i != cnt.end() ; ++i)
		{
			if (i->second > 2)
				return 0;
			else if (i->second == 1)
				ans = ans << 1;
		}

		return ans;
	}
}

int main()
{
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);

	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);
		St::insert(a[i]);
	}

	long long ans = St::get_ans();

	printf("%lld\n", ans % p);

	int x, k;
	while (m--)
	{
		scanf("%d %d", &x, &k);
		St::remove(a[x]);
		St::insert(k);

		if (St::cnt[k] == 3)
			ans = 0;
		else
		{
			if (St::cnt[k] == 1)
				ans = ans << 1;
			else if (St::cnt[k] == 2)
				ans = ans >> 1;

			if (St::cnt[a[x]] == 0)
				ans = ans >> 1;
			else if (St::cnt[a[x]] == 1)
				ans = ans << 1;
			else if (St::cnt[a[x]] == 2)
				ans = St::get_ans();
		}

		a[x] = k;
		printf("%lld\n", ans & p);
	}
	return 0;
}
