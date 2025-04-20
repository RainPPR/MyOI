#include <cstdio>

using namespace std;

int main()
{
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	int ans;
	if (a < 0)
		ans = -a * c + d + b * e;
	else if (a == 0)
		ans = d + b * e;
	else
		ans = (b - a) * e;

	printf("%d\n", ans);
	return 0;
}
