#include <cstdio>
int main()
{
	int T;
	long long n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &n);
		if (n & 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
