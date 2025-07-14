#include <cstdio>

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int group = k - 1;
	int each = n * m - group * 2;

	int x = 1, y = 1;
	for (int i = 1 ; i <= group ; ++i)
	{
		printf("%d ", 2);

		for (int j = 0 ; j < 2 ; ++j)
		{
			printf("%d %d ", x, y);

			if (x & 1)
				++y;
			else
				--y;

			if (y < 1)
				y = 1, ++x;
			else if (y > m)
				y = m, ++x;
		}

		putchar('\n');
	}

	printf("%d ", each);

	for (int j = 0 ; j < each ; ++j)
	{
		printf("%d %d ", x, y);
		if (x & 1)
			++y;
		else
			--y;

		if (y < 1)
			y = 1, ++x;
		else if (y > m)
			y = m, ++x;
	}

	return 0;
}
