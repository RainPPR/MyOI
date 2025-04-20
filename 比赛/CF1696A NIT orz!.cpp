#include <cstdio>

using namespace std;

int MAX(const int &a, const int &b)
{
	return (a > b) ? a : b;
}

int main()
{
	int t;
	scanf("%d", &t);

	int n, z, a;
	while (t--)
	{
		scanf("%d %d", &n, &z);

		int cmax = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			cmax = MAX(cmax, a | z);
		}

		printf("%d\n", cmax);
	}

	return 0;
}
