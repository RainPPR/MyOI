#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

struct Id
{
	int a, b, c, d, e, f;

	Id()
	{
		a = b = c = d = e = f = 0;
	}
	Id(int _a, int _b, int _c, int _d, int _e, int _f)
	{
		a = _a, b = _b, c = _c, d = _d, e = _e, f = _f;
	}

	bool operator < (const Id &x) const
	{
		if (a == x.a)
			if (b == x.b)
				if (c == x.c)
					if (d == x.d)
						if (e == x.e)
							return f < x.f;
						else
							return e < x.e;
					else
						return d < x.d;
				else
					return c < x.c;
			else
				return b < x.b;
		else
			return a < x.a;
	}
};

int main()
{
	int T, n;
	scanf("%d", &T);

	Id temp;
	while (T--)
	{
		map<Id, int> cnt;

		scanf("%d", &n);
		for (int i = 0 ; i < n ; ++i)
		{
			scanf("%d %d %d %d %d %d", &temp.a, &temp.b, &temp.c, &temp.d, &temp.e, &temp.f);
			++cnt[temp];
		}

		for (pair<Id, int> i : cnt)
			printf("%02d %08d %04d %04d %04d %04d %d\n", i.first.a, i.first.b, i.first.c, i.first.d, i.first.e, i.first.f, i.second);
		putchar('\n');
	}

	return 0;
}
