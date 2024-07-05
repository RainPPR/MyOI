#include <cstdio>

using namespace std;

int ex_gcd(int a, int b, int &x, int &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main()
{
	int n, a, b, m;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d", &a, &b, &m);

		int x, y;
		int d = ex_gcd(a, m, x, y);
		if (b % d)
			printf("impossible\n");
		else
			printf("%lld\n", (long long)b / d * x % m);
	}
	return 0;
}
