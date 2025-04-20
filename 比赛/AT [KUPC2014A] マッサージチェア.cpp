#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int a[3], b[3];
	scanf("%d %d %d", a, a + 1, a + 2);
	scanf("%d %d %d", b, b + 1, b + 2);

	sort(a, a + 3);
	sort(b, b + 3);

	int cmin = 2e9;
	do
	{
		cmin = min(cmin, abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(a[2] - b[2]));
	} while (next_permutation(a, a + 3));

	printf("%d\n", cmin);
	return 0;
}
