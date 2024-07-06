#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

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
	int n, a, b, x, y;
	scanf("%d", &n);
	while (n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		ex_gcd(a, b, x, y);
		printf("%d %d\n", x, y);
	}
	return 0;
}
