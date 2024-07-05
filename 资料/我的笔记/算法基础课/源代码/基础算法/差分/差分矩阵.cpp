#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1010;
int n, m, q;
int a[N][N], b[N][N];
void add(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}
int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
		{
			scanf("%d", a[i] + j);
			add(i, j, i, j, a[i][j]);
		}
	while (q--)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0, c = 0;
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
		add(x1, y1, x2, y2, c);
	}
	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= m ; ++j)
		{
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
