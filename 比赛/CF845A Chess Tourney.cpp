#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 210;

int a[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1 ; i <= 2 * n ; ++i)
		scanf("%d", a + i);

	sort(a + 1, a + 1 + 2 * n);

	if (a[n] == a[n + 1])
		printf("NO");
	else
		printf("YES");

	return 0;
}
