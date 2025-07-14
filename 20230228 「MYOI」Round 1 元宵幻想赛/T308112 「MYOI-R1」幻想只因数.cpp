#include <cstdio>
#include <unordered_set>

using namespace std;

bool isKun(const int &x, const int &n)
{
	int res = (n - 1) * n;

	while (1)
	{
		if (res >= x)
		{
			if (res > x)
				return false;
			else
				return true;
		}

		res = res * n;
		res = res + n - 1;

		if (res >= x)
		{
			if (res > x)
				return false;
			else
				return true;
		}

		res = res * n;
	}

	return false;
}

int main()
{
	int T, a;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &a);

		bool flag = true;
		for (int i = 2 ; i <= 9 ; ++i)
		{
			if (isKun(a, i))
			{
				flag = false;
				printf("%d\n", i);
				break;
			}
		}

		if (flag)
			printf("-1\n");
	}
	return 0;
}
