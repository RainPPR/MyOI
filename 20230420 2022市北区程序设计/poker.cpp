// T1: À­´ó³µ

#include <cstdio>

using namespace std;

const int N = 1e4 + 10;

int st[N], top;
int ans[2];

int main()
{
	int n, t;
	scanf("%d", &n);

	bool c = false;
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d", &t);
		st[top++] = t;

		for (int j = top - 2 ; j >= 0 ; --j)
		{
			if (st[j] == t)
			{
				ans[c] += top - j;
				top = j;
				c = !c;
				break;
			}
		}

		c = !c;
	}

	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}

