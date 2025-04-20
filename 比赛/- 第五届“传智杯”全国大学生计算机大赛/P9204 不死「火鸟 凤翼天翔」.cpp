#include <cstdio>
#include <cmath>

int main()
{
	long long x1, y1, x2, y2;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

	if ((x1 + y1) % 2 != (x2 + y2) % 2)
		printf("-1\n");

	else
	{
		long long sx = abs(x1 - x2), sy = abs(y1 - y2), s = sx + sy;

		if (x2 > x1 && y2 > y1)
			s -= (y2 - y1) % 2;
		else if (x2 < x1 && y2 < y1)
			s -= (y1 - y2) % 2;
		else if (x2 >= x1 && y2 <= y1)
			s += (y1 - y2) % 2;
		else
			s += (y2 - y1) % 2;

		printf("%lld", s);
	}

	return 0;
}
