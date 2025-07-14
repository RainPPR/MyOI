#include <cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	int a;
	while (t--)
	{
		scanf("%d", &a);

		int ans = a & -a;
		if (ans == a)
			++ans;
		if (a == 1)
			++ans;

		printf("%d\n", ans);
	}
	return 0;
}
