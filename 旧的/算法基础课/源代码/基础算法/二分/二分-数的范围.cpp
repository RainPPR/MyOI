#include<iostream>
#include<cstdio>
using namespace std;
int n = 0, q = 0;
int a[100010] = {0};
int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", a + i);
	for (int i = 0 ; i < q ; ++i)
	{
		int x = 0;
		scanf("%d", &x);
		// ◊Û±ﬂΩÁ
		int l = 0;
		int r = n - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (a[mid] >= x)
				r = mid;
			else
				l = mid + 1;
		}
		// ”“±ﬂΩÁ
		if (a[l] != x)
		{
			printf("-1 -1\n");
		}
		else
		{
			printf("%d ", l);
			l = 0;
			r = n - 1;
			while (l < r)
			{
				int mid = l + r + 1 >> 1;
				if (a[mid] <= x)
					l = mid;
				else
					r = mid - 1;
			}
			printf("%d\n", l);
		}
	}
	return 0;
}
