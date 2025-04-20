#include <cstdio>
#include <cmath>

using namespace std;

float logn(int a, int b)
{
	return log(b) / log(a);
}

bool isFail(int a, int b)
{
	return b > logn(a, 1e9);
}

int qPow(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

int main()
{
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);

	int a, b;
	scanf("%d %d", &a, &b);
	if (isFail(a, b))
		printf("-1\n");
	else
		printf("%d\n", qPow(a, b));

	fclose(stdin);
	fclose(stdout);
	return 0;
}
