#include <cstdio>
#include <cmath>

using namespace std;

inline long long bmod(long long a, long long b)
{
//	if (a < 0 && b < 0)
//		return bmod(-a, -b);
//	while (a < 0)
//		a += b;
//	return a % b;
	return (a % b + b) % b;
}

int main()
{
	char op[5];
	int T;
	long long a, b, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s %lld %lld", op, &a, &b);
		switch (op[0])
		{
			case 'p':
				ans = a + b;
				break;
			case 'r':
				ans = a - b;
				break;
			case 'm':
				ans = a * b;
				break;
			case 'b':
				ans = bmod(a, b);
				break;
			case 'l':
				ans = floor(a * 1.0 / b);
				break;
			case 'c':
				ans = ceil(a * 1.0 / b);
				break;
			default:
				ans = -1;
				break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
