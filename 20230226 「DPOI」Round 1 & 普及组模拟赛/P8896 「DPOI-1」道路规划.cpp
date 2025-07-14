#include <cstdio>

using namespace std;

void opt(bool isOK)
{
	if (isOK)
		putchar('Y'), putchar('E'), putchar('S');
	else
		putchar('N'), putchar('O');
	putchar('\n');
}

const int N = 1e5 + 10;
int l[N], r[N];

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int n;
		scanf("%d", &n);
		long long count_edge = n * (n - 1) * 0.5;

		long long count_l = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			scanf("%d", l + i);
			count_l += l[i];
		}

		long long count_r = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			scanf("%d", r + i);
			count_r += r[i];
		}

		if ((count_edge < count_l) || (count_edge > count_r))
			opt(false);
		else
		{
			opt(true);
		}
	}
	return 0;
}
