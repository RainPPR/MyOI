#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int n, m, x;
int main()
{
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", a + i);
	for (int i = 0 ; i < m ; ++i)
		scanf("%d", b + i);
	for (int i = 0, j = m - 1 ; i < n ; ++i)
	{
		while ((j >= 0) && (a[i] + b[j] > x))
			--j;
		if ((j >= 0) && (a[i] + b[j] == x))
		{
			printf("%d %d\n", i, j);
			break;
		}
	}
	return 0;
}
