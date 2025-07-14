#include <cstdio>

using namespace std;

const int N = 110;

int n;
int a[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);
		a[i] += a[i - 1];
	}

	int cmax = -2e9;
	for (int l = 1 ; l <= n ; ++l)
	{
		for (int r = l ; r <= n ; ++r)
		{
			int now = a[n] + r - l + 1 + 2 * (a[l - 1] - a[r]);
			cmax = (now > cmax) ? now : cmax;
		}
	}

	printf("%d\n", cmax);
	return 0;
}
